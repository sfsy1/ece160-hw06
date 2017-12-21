#include "MastersStudent.h"
#include <numeric>

MastersStudent::MastersStudent(Student ug, int msy): 
    Student(ug), _ms_grad_year(msy) {
	}
  
MastersStudent::MastersStudent(std::string fn, std::string ln,
    int ugy, int msy, Major m):
    Student(fn, ln, ugy, m), _ms_grad_year(msy) {}

float MastersStudent::getMsGpa() { 
	if (_ms_grades.size() != 0) {
		return accumulate(_ms_grades.begin(), _ms_grades.end(),0.00)/_ms_grades.size();
	}
	return 0.0;
}

void MastersStudent::addMsGrade(float grade) { 
	    _ms_grades.push_back(grade);
}

void MastersStudent::printInfo() {
	Student::printInfo();
  printf("MSa %s: %d\nMS GPA: %1.2f",
  Student::majorString(_major).c_str(), _ms_grad_year, getMsGpa());
}