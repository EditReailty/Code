#pragma once
class List
{
public:
	int m_A;
	int m_B;
	int m_C;
	 
	//List() {
	//	m_A = 0; // 初始化成员变量A
	//	m_B = 0; // 初始化成员变量B
	//	m_C = 0; // 初始化成员变量C
	//}

	//初始化列表的语法
	List() : m_A(10), m_B(20), m_C(30) {
	}
	List(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {
		// 使用初始化列表对成员变量进行初始化
	}

};

