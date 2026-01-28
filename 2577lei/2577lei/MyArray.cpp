#include "MyArray.h"
#include <iostream>
using namespace std;

MyArray::MyArray()
{
	cout << "无参构造函数执行了..." << endl;
	m_Capacity = 100; // 默认容量
	m_Size = 0; // 初始大小为0
	pAddress = new int[m_Capacity]; // 分配内存
}

MyArray::MyArray(int capacity)
{
	cout << "有参构造函数执行了..." << endl;
	m_Capacity = capacity; // 设置数组容量
	m_Size = 0; // 初始大小为0
	pAddress = new int[m_Capacity]; // 分配内存
}

MyArray::MyArray(const MyArray& arr)
{
	cout << "拷贝构造函数执行了..." << endl;
	m_Capacity = arr.m_Capacity; // 复制容量
	m_Size = arr.m_Size; // 复制大小
	pAddress = new int[m_Capacity]; // 分配新的内存
	for (int i = 0; i < m_Size; ++i) {
		pAddress[i] = arr.pAddress[i]; // 深拷贝数组数据
	}
}

MyArray::~MyArray()
{
	cout << "析构函数执行了..." << endl;
	if (pAddress != nullptr) {
		delete[] pAddress; // 释放内存
		pAddress = nullptr; // 避免悬空指针
	}
	m_Capacity = 0; // 重置容量
	m_Size = 0; // 重置大小
}

void MyArray::pushBack(int data)
{
	pAddress[m_Size] = data;
	m_Size++; // 增加数组大小
}

int MyArray::getData(int position)
{
	return pAddress[position];
}

void MyArray::setData(int position, int data)
{
	if (position >= 0 && position < m_Size) {
		pAddress[position] = data; // 设置指定位置的数据
	}
	else {
		cout << "位置越界，无法设置数据。" << endl;
	}
}
