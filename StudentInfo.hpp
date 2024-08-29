#pragma once

#include <string>

class StudentInfo {
public:
	//Time complexity would be O(1) since it can be done in constant time
	int getAge() const {
		return age;
	}

	//Time complexity would be O(1) since it can be done in constant time
	void setAge(int age) {
		this->age = age;
	}

	//Time complexity would be O(1) since it can be done in constant time
	const std::string& getGender() const {
		return gender;
	}

	//Time complexity would be O(1) since it can be done in constant time
	void setGender(const std::string &gender) {
		this->gender = gender;
	}

	//Time complexity would be O(1) since it can be done in constant time
	const std::string& getMajor() const {
		return major;
	}

	//Time complexity would be O(1) since it can be done in constant time
	void setMajor(const std::string &major) {
		this->major = major;
	}

	//Time complexity would be O(1) since it can be done in constant time
	const std::string& getName() const {
		return name;
	}

	//Time complexity would be O(1) since it can be done in constant time
	void setName(const std::string &name) {
		this->name = name;
	}

	//Time complexity would be O(1) since it can be done in constant time
	const std::string& getYear() const {
		return year;
	}

	//Time complexity would be O(1) since it can be done in constant time
	void setYear(const std::string &year) {
		this->year = year;
	}

	//Time complexity would be O(1) since it can be done in constant time
	int getStudentId() const {
		return studentID;
	}

	//Time complexity would be O(1) since it can be done in constant time
	void setStudentId(int studentId) {
		studentID = studentId;
	}

private:
	int studentID;
	std::string name;
	std::string year;
	int age;
	std::string major;
	std::string gender;



};
