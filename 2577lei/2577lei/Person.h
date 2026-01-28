#pragma once
#include<iostream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;
class Person
{
public:
	char* m_Name;
	int m_Age;
	//普通的构造函数
	Person() {
		m_Name = nullptr;
		m_Age = 0;
		cout << "无参的构造函数执行了..." << endl;
	}
	Person(const char* name, int age) {
		m_Name = new char[strlen(name) + 1]; // 分配内存
		strcpy(m_Name, name); // 复制字符串
		m_Age = age;
		cout << "有参的构造函数执行了..." << endl;
	}
	//拷贝构造函数
	Person(const Person& p) {
		//浅拷贝
		/*m_Name = p.m_Name;
		m_Age = p.m_Age;*/
		//深拷贝
		m_Name = new char[strlen(p.m_Name) + 1]; // 分配新的内存
		strcpy(m_Name, p.m_Name); // 复制字符串
		m_Age = p.m_Age; // 复制年龄
		cout << "拷贝构造函数执行了..." << endl;
	}
	~Person() {
		if (m_Name != nullptr) {
			delete[] m_Name; // 释放内存
			m_Name = nullptr; // 避免悬空指针
		}
		cout << "析构函数执行了..." << endl;
	}
};

