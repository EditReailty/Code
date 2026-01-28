#pragma once
#include<iostream>
using namespace std;
template<typename T1, typename T2>
class Person6
{
public:
	Person6(T1 name, T2 age);
	void showPerson6();
	T1 m_Name;
	T2 m_Age;
};

template<typename T1, typename T2>
Person6<T1, T2>::Person6(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}
template<typename T1, typename T2>
void Person6<T1, T2>::showPerson6() {
	cout << "ÐÕÃû£º" << this->m_Name << ",ÄêÁä£º" << this->m_Age << endl;
}
