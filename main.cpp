#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include "Date.hpp"
#include "PriorityQueue.hpp"
#include "SortVector.hpp"
#include "HashTableOpen.hpp"
#include "StudentInfo.hpp"

using namespace std;

//function prototypes

//prompts the user to enter a new user
StudentInfo newUserPrompt(int newStudentID);
// Load the order data from a file, and store it in the given vector
void readStudentData(vector<StudentInfo> &v, std::string filename);
// Load the order data from a file, and store it in the given vector
void readAppointments(vector<Date> &v, std::string filename);
//function that prompts user to enter a date and returns a newly created date
Date createDate();


//Time complexity would be O(n+m+o) n being the number of times the user goes throught the menu
//m being the number of items in the students.csv file and o being the number of items in
//the appointments.csv
int main() {
	vector<StudentInfo> studentInfoData;
	vector<Date> appointmentData;
	Dictionary<int, StudentInfo> *studentsDict = new HashTableOpen<int, StudentInfo>(2000);
	PriorityQueue *appointmentsQueue = new PriorityQueue(25);
	//reading file called "students.csv" into the vector
	readStudentData(studentInfoData, "cs20-final-project-StephenHu04/students.csv");
	//reading file called "appointments.csv" into the vector
	readAppointments(appointmentData, "cs20-final-project-StephenHu04/appointments.csv");
	//inserting the data read from csv file into the dictionary
	StudentInfo temp;
	for (unsigned i = 0; i < studentInfoData.size(); i++) {
		temp.setAge(studentInfoData[i].getAge());
		temp.setGender(studentInfoData[i].getGender());
		temp.setMajor(studentInfoData[i].getMajor());
		temp.setName(studentInfoData[i].getName());
		temp.setStudentId(studentInfoData[i].getStudentId());
		temp.setYear(studentInfoData[i].getYear());
		studentsDict->insert(temp.getStudentId(), temp);
	}

	for (unsigned i = 0; i < appointmentData.size(); i++) {
		appointmentsQueue->insert(appointmentData[i]);
	}
	SortVector vSort;
	cout << "         -----Welcome to CounselEase!-----\n"
			<< "Make the easy, easier! Made for counselors by students.\n";
	int userChoice = 0;
	do {
		//display menu for options user can have
		cout << "\nWhat would you like to do?\n" << "\t1. Student data\n" //here you can choose between storing new data or accessing data
				<< "\t2. Appointments\n" //here you can create new appointments, find appointments, or find closest appointment date
				<< "\t3. Sort student data\n"	//sort by population, age, name, etc
				<< "\t4. exit\n" << "Enter your choice: ";
		cin >> userChoice;

		//user picked choice 1, they can manipulate student data
		if (userChoice == 1) {
			int newUserChoice = 0;
			int newStudentID;
			StudentInfo info;
			//prompts another sub-menu for the user to choose from
			do {
				cout << "\nWhat would you like to do?\n"
						<< "\t1. Insert new student\n" << "\t2. Find student\n"
						<< "\t3. Go back\n" << "Enter your choice: ";
				cin >> newUserChoice;
				//inserts new student into the dictionary
				if (newUserChoice == 1) {
					bool studentFound = true;
					cout << "\nPlease enter an eight digit student ID #: ";
					cin >> newStudentID;
					try {
						info = studentsDict->find(newStudentID);
					} catch (const string &e) {
						//if student is not in the dictionary
						studentFound = false;
						cout
								<< "New student confirmed! Please fill out the following information...\n";
						info = newUserPrompt(newStudentID);
						//push the new data into the open hash table
						studentsDict->insert(newStudentID, info);
						//updates the vector with the new student
						studentInfoData.push_back(info);
					}

					if (studentFound == true) {
						//checks if there is an existing ID in the open hash table, if there is give option to overwrite.
						cout
								<< "Error: Student ID is already in the system...\n"
								<< "Student: " << info.getName() << " ("
								<< info.getGender() << ") " << endl;
						cout << "Major: " << info.getMajor() << endl;
						cout << "Age: " << info.getAge() << endl;
						cout << "Year: " << info.getYear() << endl << endl;
						string overwrite;
						do {
							cout << "Would you like to overwrite?\n"
									<< "Enter(yes/no): ";
							cin >> overwrite;
						} while (!((overwrite == "yes") || (overwrite == "no")));
						if (overwrite == "yes") {
							cout << "\nOverwriting confirmed! Please fill out the following information...\n";
							info = newUserPrompt(newStudentID);
							//replaces old student info from dictionary
							studentsDict->remove(newStudentID);
							studentsDict->insert(newStudentID, info);
							//updates the students in the student vector by first sorting the vector,
							vSort.bubbleSort(studentInfoData, 1);
							//after sorting the vector, use a binary search to find id and remove from vector
							vSort.overwriteValue(studentInfoData, info, 0,
									studentInfoData.size() - 1);
						}
					}

				}
				//this finds a student in the dictiionary
				else if (newUserChoice == 2) {
					cout << "\nPlease enter an eight digit student ID #: ";
					cin >> newStudentID;
					bool found = true;
					try {
						info = studentsDict->find(newStudentID);
					} catch (const string &e) {
						//if they cant find the student id
						found = false;
						cout << e << endl;
					}

					if (found) {
						//prompts user that data in in the dictionary and prints out info if found
						cout << "Student found!\n" << "Student: "
								<< info.getName() << " (" << info.getGender()
								<< ") " << endl;
						cout << "Major: " << info.getMajor() << endl;
						cout << "Age: " << info.getAge() << endl;
						cout << "Year: " << info.getYear() << endl;
						string remove;
						do {
							cout
									<< "\nWould you like to remove student from database?\n"
									<< "Enter(yes/no): ";
							cin >> remove;
						} while (!((remove == "yes") || (remove == "no")));
						if (remove == "yes") {
							cout << "Student removed...\n";
							studentsDict->remove(newStudentID);
							//updates the students in the student vector by first sorting the vector,
							vSort.bubbleSort(studentInfoData, 1);
							//after sorting the vector, use a binary search to find id and remove from vector
							vSort.removeValue(studentInfoData, newStudentID, 0,
									studentInfoData.size() - 1);
						}
					}
				}
			} while (newUserChoice != 3);
		}

		//user picked choice 2, they can access all appointments
		else if (userChoice == 2) {
			int newUserChoice;
			do {
				cout << "\nHow would you like to do?\n"
				<< "\t1. Find closest appointment\n" << "\t2. Insert New Appointment\n"
				<< "\t3. Cancel an appointment\n"
				<< "\t4. Print out all appointments\n " << "\t5. Go back\n "
				<< "Enter your choice: ";
				cin >> newUserChoice;

				//finds closest appointment using a priority queue
				if (newUserChoice == 1) {
					if(appointmentsQueue->total == 0){
						cout << "\nYou're all good! No appointments found.\n";
					}
					else{
						Date temp;
						temp = appointmentsQueue->findMin();
						cout << "\nAppointment confirmed! Closest appointment:\n"
							   << "                " << temp << endl;
					}
				}
				//inserts a new appointment into the priority queue
				if (newUserChoice == 2) {
					Date temp = createDate();
					if(appointmentsQueue->insert(temp)){
						appointmentData.push_back(temp);
						cout << "Success! Appointment booked!\n";
					}
					else{
						cout << "Uh oh! You have reached the maximum number of appointments possible!"
								<< "\nCanceling created appointment...\n";
					}

				}
				//removes an appointment from the priority queue
				if (newUserChoice == 3) {
					Date temp = createDate();
					vSort.bubbleSort(appointmentData);
					bool flag = vSort.validDate(appointmentData, temp);
					if(flag){
						vSort.removeValue(appointmentData, temp, 0, appointmentData.size() - 1);
						PriorityQueue *tempAppointmentsQueue = new PriorityQueue(25);
						for (unsigned i = 0; i < appointmentData.size(); i++) {
							tempAppointmentsQueue->insert(appointmentData[i]);
						}
						appointmentsQueue = tempAppointmentsQueue;
						cout << "Success! Appointment canceled!\n";
					}
					else{
						cout << "\t*ERROR*::Unidentified date\n";
					}
				}
				//prints out all appointments
				if (newUserChoice == 4) {
					vSort.bubbleSort(appointmentData);
					vSort.printDate(appointmentData);
				}

			}while(!(newUserChoice == 5));
		}
		//user picked choice 3, they can sort and print all student information
		else if (userChoice == 3) {
			int newUserChoice;
			do {
				cout << "\nHow would you like your data sorted by?\n"
						<< "\t1. Student ID\n" << "\t2. Name\n" << "\t3. Age\n"
						<< "\t4. Major\n " << "\t5. Go back\n "
						<< "Enter your choice: ";
				cin >> newUserChoice;
				if (newUserChoice == 1) {
					//sort it by id
					vSort.bubbleSort(studentInfoData, 1);
					vSort.printData(studentInfoData);

				}
				if (newUserChoice == 2) {
					//sort it by name
					vSort.bubbleSort(studentInfoData, 2);
					vSort.printData(studentInfoData);
				}
				if (newUserChoice == 3) {
					//sort it by age
					vSort.bubbleSort(studentInfoData, 3);
					vSort.printData(studentInfoData);
				}
				if (newUserChoice == 4) {
					//sort it by major
					vSort.bubbleSort(studentInfoData, 4);
					vSort.printData(studentInfoData);
				}

			} while (!(newUserChoice == 5));
		}

	} while (userChoice != 4);
	delete studentsDict;
	return 0;
}



//Time complexity would be O(1) since it can be done in constant time
StudentInfo newUserPrompt(int newStudentID) {
	StudentInfo info;
	cout << "Student name: ";
	string stringTemp;
	int intTemp;
	//set name
	cin.ignore();
	getline(cin, stringTemp);
	info.setName(stringTemp);
	//set student ID
	info.setStudentId(newStudentID);
	//set major
	cout << "Major: ";
	getline(cin, stringTemp);
	info.setMajor(stringTemp);
	//set age
	cout << "Age: ";
	cin >> intTemp;
	info.setAge(intTemp);
	//set gender
	cout << "Gender: ";
	cin.ignore();
	getline(cin, stringTemp);
	info.setGender(stringTemp);
	//set year
	cout << "Year: ";
	getline(cin, stringTemp);
	info.setYear(stringTemp);

	return info;
}

//Time complexity would be O(n) n being the number of items in the file
void readStudentData(vector<StudentInfo> &v, string filename) {
	ifstream f;
	string line;

	f.open(filename, ios::in);
	if (!f.is_open()) {
		throw string("Error opening file " + filename);
	}

	while (!f.eof()) {
		getline(f, line);
		if (line == "")
			continue;
		string temp;
		StudentInfo tempInfo;
		stringstream ss(line);
		getline(ss, temp, ',');
		tempInfo.setStudentId(stoi(temp));
		getline(ss, temp, ',');
		tempInfo.setName(temp);
		getline(ss, temp, ',');
		tempInfo.setYear(temp);
		getline(ss, temp, ',');
		tempInfo.setAge(stoi(temp));
		getline(ss, temp, ',');
		tempInfo.setGender(temp);
		getline(ss, temp, ',');
		tempInfo.setMajor(temp);
		v.push_back(tempInfo);
	}

	f.close();
}

//Time complexity would be O(n) n being the number of items in the file
void readAppointments(vector<Date> &v, string filename) {
	ifstream f;
	string line;

	f.open(filename, ios::in);
	if (!f.is_open()) {
		throw string("Error opening file " + filename);
	}

	while (!f.eof()) {
		getline(f, line);
		if (line == "")
			continue;
		string temp;
		int day = 0;
		int month = 0;
		int year = 0;
		bool flag1,flag2,flag3;
		Date tempInfo;
		stringstream ss(line);
		getline(ss, temp, ',');
		year = stoi(temp);
		//flag that makes sure year is set correctly
		flag1 = tempInfo.setYear(year);
		getline(ss, temp, ',');
		month = stoi(temp);
		//flag that makes sure month is set correctly
		flag2 = tempInfo.setMonth(month, year);
		getline(ss, temp, ',');
		day = stoi(temp);
		//flag that makes sure day is set correctly
		flag3 = tempInfo.setDay(day, month, year);
		//push Date into vector if all flags are true
		//all true meaning the values for the dates were valid
		if(flag1 && flag2 && flag3 ){
			v.push_back(tempInfo);
		}
	}

	f.close();
}

//Time complexity would be O(n) n being the number of times the user incorrectly enters the date
Date createDate() {
	string date;
	string tempString;
	Date tempDate;
	int year;
	int month;
	int day;
	bool flag1, flag2, flag3;
	do {
		cout << "\nPlease enter a date in a MM/DD/YYYY format: ";
		cin >> date;
		stringstream ss(date);
		getline(ss, tempString, '/');
		month = stoi(tempString);
		getline(ss, tempString, '/');
		day = stoi(tempString);
		getline(ss, tempString, '/');
		year = stoi(tempString);
		//flag that makes sure year is set correctly
		flag1 = tempDate.setYear(year);
		//flag that makes sure month is set correctly
		flag2 = tempDate.setMonth(month, year);
		//flag that makes sure day is set correctly
		flag3 = tempDate.setDay(day, month, year);
		//if one variable was set incorrectly with an invalid value
		if (!(flag1 && flag2 && flag3)) {
			cout << "\n\t****ERROR****\nPlease enter a valid Date\n";
		}
	} while (!(flag1 && flag2 && flag3));
	return tempDate;
}
