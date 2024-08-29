#pragma once
#include <vector>
#include <iomanip>
#include <iostream>
#include "StudentInfo.hpp"
#include "Date.hpp"

class SortVector {
private:

	// A function that compares the left and right value depending on x given
	//different value for x corresponds to different elements that are compared
	bool lessThan(const StudentInfo &left, const StudentInfo &right, int x);

	// Swap two pieces of data in the given array
	void swap(std::vector<StudentInfo> &v,int i, int j);

	//A function that compares the left and right value
	bool lessThan(Date &left, Date &right);

	// Swap two pieces of data in the given array
	void swap(std::vector<Date> &v,int i, int j);

public:

	//uses a binary search algorithm that recursively calls itself to update the information in vector
	void overwriteValue(std::vector<StudentInfo> &v, StudentInfo newInfo, int left, int right);

	//similar to the overwriteValue function, it uses binary search recursively, but this times removes it from vector;
	void removeValue(std::vector<StudentInfo> &v, int studentID, int left, int right);

	//sorts the vector using a bubble sort, depending on x
	//different value for x corresponds to how the vector is sorted
	//if x == 1 it is sorted by student ids, if x == 2 it is sorted by name
	void bubbleSort(std::vector<StudentInfo> &v, int x);

	//function to print out all student data in the vector
	void printData(std::vector<StudentInfo> &v);

	//sorts a vector using bubble sort
	void bubbleSort(std::vector<Date> &v);

	//return true if value is in vector
	bool validDate(std::vector<Date> &v, Date date);

	//remove value in vector using binary search algorithm
	void removeValue(std::vector<Date> &v, Date date, int left, int right);

	//print all dates
	void printDate(std::vector<Date> &v);
};
