#pragma once
#include<string>

using namespace std;

//声明一个类，class 关键字{}
class Student {
protected: //访问权限，protected表示保护成员，可以在类的内部和派生类中访问
	//protected成员可以被继承，但不能被外部直接访问
	//这里没有成员变量，通常用于继承时使用
private: //访问权限，private表示私有成员，只能在类的内部访问
	string m_Name; //姓名
	int m_Age;     //年龄
	int m_Id;      //学号
public: //访问权限，public表示公有成员，可以被外部访问
	void sleep(); //睡觉的方法
	void eat();	  
	void study();
	void setName(string name);
	string getName();
	void setAge(int age);
	int getAge();
	void setId(int id);
	int getId();
};