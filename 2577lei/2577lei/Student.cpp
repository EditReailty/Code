#include "Student.h"
#include<iostream>

using namespace std;

void Student::sleep() {
	cout << "学生睡觉" << endl;
}
void Student::eat() {
	cout << "学生吃饭" << endl;
}
void Student::study() {
	cout << "学生学习" << endl;
}
void Student::setName(string name) {
	m_Name = name;
}
string Student::getName() {
	return m_Name;
}
void Student::setAge(int age) {
	m_Age = age;
}
int Student::getAge() {
	return m_Age;
}
void Student::setId(int id) {
	m_Id = id;
}
int Student::getId() {
	return m_Id;
}
