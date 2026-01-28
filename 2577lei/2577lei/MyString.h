#pragma once
#include <cstring>
#include <iostream>
#pragma warning(disable: 4996) // 禁用安全警告，允许使用strcpy等函数
using namespace std;
class MyString
{
	friend MyString operator+(const char* str, const MyString& myStr)
	{
		char* newString = new char[strlen(str) + myStr.m_Length + 1] {}; // 分配新的内存
		strcat(newString, str); // 连接其他字符串
		strcat(newString, myStr.pString); // 连接MyString字符串
		MyString result(newString); // MyString result = newString;
		delete[] newString; // 释放临时字符串内存
		return result;
	}
	friend ostream& operator<<(ostream& os, MyString& str) {
		os << "MyString: " << str.pString;
		return os;
	};
	friend istream& operator>>(istream& in, MyString& str) {
		//先判断原来是否有数据，如果有先释放
		if(str.pString != nullptr) {
			delete[] str.pString; // 释放原有内存
			str.pString = nullptr; // 避免悬空指针
		}
		char buffer[1024]; // 临时缓冲区
		cin >> buffer; // 从输入流读取字符串
		str.m_Length = strlen(buffer); // 获取新字符串的长度
		str.pString = new char[str.m_Length + 1]; // 分配新的内存
		strcpy(str.pString, buffer); // 复制新字符串到pString
		return in; // 返回输入流	
	}
public:
	MyString(const char* str);
	MyString(const MyString& other); // 拷贝构造函数
	~MyString();
	int length() const { // 获取字符串长度
		return m_Length;
	}
	MyString operator+(const MyString& other) const;
	MyString operator+(const char* str) const;// 返回副本，避免修改原对象
	MyString& operator=(const char* str);// 返回引用，可以是左值（链式），减少拷贝开销
	MyString& operator=(const MyString& other);
	char& operator[](int index) ;
	bool operator==(const MyString& other) const;
	bool operator==(const char* str) const;
	MyString& operator+=(const MyString& other);
	MyString& operator+=(const char* str);
private:
	char* pString;//维护在底层的，在堆区创建字符数组
	int m_Length; // 字符串的长度，不包括'\0'结尾符
};

