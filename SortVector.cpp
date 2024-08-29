#include "SortVector.hpp"

//Time complexity would be O(1) since it can be done in constant time
bool SortVector::lessThan(const StudentInfo &left, const StudentInfo &right,
		int x) {
	//compares left student id and right student-id if it is less
	if (x == 1) {
		return left.getStudentId() < right.getStudentId();
	}
	//compares left name and right name if it is less
	else if (x == 2) {
		return left.getName() < right.getName();
	} else if (x == 3) {
		return left.getAge() < right.getAge();
	} else if (x == 4) {
		return left.getMajor() < right.getMajor();
	}
	return false;
}

//Time complexity would be O(1) since it can be done in constant time
void SortVector::swap(std::vector<StudentInfo> &v, int i, int j) {
	StudentInfo temp = v[j];
	v[j] = v[i];
	v[i] = temp;
}

//Time complexity would be O(n) where n is the number of items in the array
void SortVector::bubbleSort(std::vector<StudentInfo> &v, int x) {
//sorts it by student-id ascending order
	if (x == 1) {
		for (unsigned i = 0; i < v.size(); i++) {
			for (unsigned j = v.size() - 1; j > i; --j) {
				//compares left and right student id and returns true if right side is greater than left
				if (lessThan(v[j - 1], v[j], 1) == false) {
					swap(v, j - 1, j);
				}
			}
		}
	}
	//sorts it by name in alphabetical order
	else if (x == 2) {
		for (unsigned i = 0; i < v.size(); i++) {
			for (unsigned j = v.size() - 1; j > i; --j) {
				//compares left and right student name and returns true if right side is greater than left
				if (lessThan(v[j - 1], v[j], 2) == false) {
					swap(v, j - 1, j);
				}
			}
		}
	}
	//sorts it by age ascending order
	else if (x == 3) {
		for (unsigned i = 0; i < v.size(); i++) {
			for (unsigned j = v.size() - 1; j > i; --j) {
				//compares left and right student age and returns true if right side is greater than left
				if (lessThan(v[j - 1], v[j], 3) == false) {
					swap(v, j - 1, j);
				}
			}
		}
	}
	//sorts it by major in alphabetical order
	else if (x == 4) {
		for (unsigned i = 0; i < v.size(); i++) {
			for (unsigned j = v.size() - 1; j > i; --j) {
				//compares left and right student major and returns true if right side is greater than left
				if (lessThan(v[j - 1], v[j], 4) == false) {
					swap(v, j - 1, j);
				}
			}
		}
	}
}


//Time complexity would be O(logn) where n is the size of the vector
//because all choices decrease by 1/2 every time
void SortVector::overwriteValue(std::vector<StudentInfo> &v,
		StudentInfo newInfo, int left, int right) {

	int middle = (right + left) / 2;
	//base case - if student id matches, update the info
	if (v[middle].getStudentId() == newInfo.getStudentId()) {
		v[middle] = newInfo;
		return;
	}
	// recursively calls the function if value in vector is less than given value
	if (v[middle].getStudentId() < newInfo.getStudentId()) {
		return overwriteValue(v, newInfo, middle + 1, right);
	}
	// recursively calls the function if value in vector is greater than given value
	else if (v[middle].getStudentId() > newInfo.getStudentId()) {
		return overwriteValue(v, newInfo, left, middle - 1);
	}
}

//Time complexity would be O(logn) where n is the size of the vector
//because all choices decrease by 1/2 every time
void SortVector::removeValue(std::vector<StudentInfo> &v, int studentID,
		int left, int right) {

	int middle = (right + left) / 2;
	//base case - if student id matches remove from vector
	if (v[middle].getStudentId() == studentID) {
		StudentInfo temp = v[middle];
		v[middle] = v[v.size() - 1];
		v.pop_back();
		return;
	}
	// recursively calls the function if value in vector is less than given value
	if (v[middle].getStudentId() < studentID) {
		return removeValue(v, studentID, middle + 1, right);
	}
	// recursively calls the function if value in vector is greater than given value
	else if (v[middle].getStudentId() > studentID) {
		return removeValue(v, studentID, left, middle - 1);
	}
}

//Time complexity would be O(n) where n is the size of the vector
void SortVector::printData(std::vector<StudentInfo> &v) {
	//header
	std::cout << "\t\t" << std::setw(15) << std::left << "Student-ID"
			<< std::setw(7) << std::left << "Age" << std::setw(20) << std::left
			<< "Name" << std::setw(20) << std::left << "Major" << std::endl;
	std::cout << "\t\t" << std::setw(15) << std::left << "------------"
			<< std::setw(7) << std::left << "-----" << std::setw(20)
			<< std::left << "-----------" << std::setw(20) << std::left
			<< "---------------" << std::endl;
	//body
	for (unsigned int i = 0; i < v.size(); i++) {
		std::cout << "\t\t" << std::setw(15) << std::left << v[i].getStudentId()
				<< std::setw(7) << std::left << v[i].getAge() << std::setw(20)
				<< std::left << v[i].getName() << std::setw(20) << std::left
				<< v[i].getMajor() << std::endl;
	}

}


//Time complexity would be O(1) since it can be done in constant time
bool SortVector::lessThan(Date &left, Date &right){
	return (left < right);
}

//Time complexity would be O(1) since it can be done in constant time
void SortVector::swap(std::vector<Date> &v, int i, int j) {
	Date temp = v[j];
	v[j] = v[i];
	v[i] = temp;
}


//Time complexity would be O(n) where n is the size of the vector
void SortVector::bubbleSort(std::vector<Date> &v) {
	for (unsigned i = 0; i < v.size(); i++) {
		for (unsigned j = v.size() - 1; j > i; --j) {
			//compares left and right student age and returns true if right side is greater than left
			if (lessThan(v[j - 1], v[j]) == false) {
				swap(v, j - 1, j);
			}
		}
	}
}

//Time complexity would be O(1) since it can be done in constant time
bool  SortVector::validDate(std::vector<Date> &v, Date date){
	for (unsigned i = 0; i < v.size(); i++){
		if(v[i] == date){
			return true;
		}
	}
	return false;
}

//Time complexity would be O(logn) where n is the size of the vector
//because all choices decrease by 1/2 every time
void SortVector::removeValue(std::vector<Date> &v, Date date, int left, int right) {
	int middle = (right + left) / 2;
	//base case - if dates, update the info
	if (v[middle] == date) {
		Date temp = v[middle];
		v[middle] = v[v.size() - 1];
		v.pop_back();
		return;
	}
	// recursively calls the function if value in vector is less than given value
	if (v[middle] < date) {
		return removeValue(v, date, middle + 1, right);
	}
	// recursively calls the function if value in vector is greater than given value
	else if (v[middle] > date) {
		return removeValue(v, date, left, middle - 1);
	}

}

//Time complexity would be O(n) where n is the size of the vector
void SortVector::printDate(std::vector<Date> &v){
	std::cout << "\n\tAppointments" << std::endl;
	std::cout << "\t------------\n";
	for (unsigned i = 0; i < v.size(); i++){
		std::cout << "\t" << v[i] << std::endl;
	}
}
