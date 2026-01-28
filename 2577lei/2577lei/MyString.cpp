#include "MyString.h"


MyString::MyString(const char* str)
{
	cout << "MyString的有参构造函数" << endl;
	m_Length = strlen(str); // 获取字符串长度
	pString = new char[m_Length + 1]; // 分配内存
	strcpy(pString, str); // 复制字符串
}

MyString::MyString(const MyString& other)
{
	cout << "MyString的拷贝构造函数" << endl;
	m_Length = other.m_Length; // 复制长度
	pString = new char[m_Length + 1]; // 分配新的内存
	strcpy(pString, other.pString); // 复制字符串内容
}

MyString::~MyString()
{
	cout << "MyString的析构函数" << endl;
	if (pString != nullptr) {
		delete[] pString; // 释放内存
		pString = nullptr; // 避免悬空指针
	}
}

MyString MyString::operator+(const MyString& other) const
{
	char* newString = new char[m_Length + other.m_Length + 1] {}; // 分配新的内存
	strcat(newString, pString); // 连接当前字符串
	strcat(newString, other.pString); // 连接其他字符串
	MyString result(newString); // MyString result = newString;
	delete[] newString; // 释放临时字符串内存
	return result;
}

MyString MyString::operator+(const char* str) const
{
	char* newString = new char[m_Length + strlen(str) + 1] {}; // 分配新的内存
	strcat(newString, pString); // 连接当前字符串
	strcat(newString, str); // 连接其他字符串
	MyString result(newString); // MyString result = newString;
	delete[] newString; // 释放临时字符串内存
	return result;
}

MyString& MyString::operator=(const char* str)
{
	if (pString != nullptr) {
		delete[] pString; // 释放原有内存
		pString = nullptr; // 避免悬空指针
	}
	m_Length = strlen(str); // 获取新字符串的长度
	pString = new char[m_Length + 1]; // 分配新的内存
	strcpy(pString, str); // 复制新字符串到pString
	return *this; // 返回当前对象的引用
}

MyString& MyString::operator=(const MyString& other)
{
	if (pString != nullptr) {
		delete[] pString; // 释放原有内存
		pString = nullptr; // 避免悬空指针
	}
	m_Length = strlen(other.pString); // 获取新字符串的长度
	pString = new char[m_Length + 1]; // 分配新的内存
	strcpy(pString, other.pString); // 复制新字符串到pString
	return *this; // 返回当前对象的引用
}

char& MyString::operator[](int index)
{
	return pString[index]; // 返回指定索引的字符
}

bool MyString::operator==(const MyString& other) const
{
	return strcmp(pString, other.pString) == 0;
}

bool MyString::operator==(const char* str) const
{
	return strcmp(pString, str) == 0;
}

MyString& MyString::operator+=(const MyString& other)
{
	MyString temp = *this + other; // 使用+运算符连接字符串
	*this = temp; // 将结果赋值给当前对象
	return *this; // 返回当前对象的引用
}

MyString& MyString::operator+=(const char* str)
{
	MyString temp = *this + str; // 使用+运算符连接字符串
	*this = temp; // 将结果赋值给当前对象
	return *this; // 返回当前对象的引用
}

