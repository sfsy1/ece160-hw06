#include "Student.h"
#include <string>
#include <stdio.h>
#include <sstream>
#include <sstream>
#include <vector>
#include <numeric>
#include <functional>

Student::Student(std::string fn, std::string ln, int y, Major m) {
  _grad_year = y;
  _first_name = fn;
  _last_name = ln;
  _major = m;
  std::vector<float> _grades;
}

Student::~Student() {}

//add grade to vector
void Student::addGrade(float grade) {
	_grades.push_back(grade);
}

//calc average GPA
float Student::getGpa() {
	return accumulate(_grades.begin(), _grades.end(), 0.00)/ _grades.size();
}

//convert majors to string
std::string Student::majorString(Major m) {
	switch(m) {
		case Major::EE: return "EE";
		case Major::ME: return "ME";
		case Major::CE: return "CE";
		case Major::CHE: return "CHE";
		case Major::BSE: return "BSE";
		case Major::ART: return "ART";
		case Major::ARCH: return "ARCH";
		default: return "Invalid Major";
	}
}

//get last name of student
const std::string& Student::getLastName() {
  return _last_name;
}		

//print
void Student::printInfo() {
	printf("%s, %s\n%s %d\nGPA: %1.2f\n", _last_name.c_str(), _first_name.c_str(), majorString(_major).c_str(), _grad_year, getGpa());
}