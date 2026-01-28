#include<iostream>
#include<string>
#include"Person6.h"
#include"MyArray.hpp"

using namespace std;

//使用函数模板实现通用的交换，类型参数化
template <typename T>//T属于通用的数据类型，告诉编译器出现T不要报错
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}
template <typename T>
void func() {

}
template <typename T>
void mySort(T arr[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				mySwap(arr[j], arr[j + 1]);
			}
		}
	}
}
template <typename T>
void printArr(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}
}
template<typename T>
T myPlus(T a, T b) {
	return a + b;
}
int myPlus2(int a, int b) {
	return a + b;
}
void myPrint(int a, int b) {
	cout << "普通函数myPrint调用" << endl;
}
template<typename T>
void myPrint(T a, T b) {
	cout << "函数模板myPrint调用" << endl;
}
template<typename T>
void myPrint(T a, T b, T c) {
	cout << "重载函数模板myPrint调用" << endl;
}
void test1() {
	int a = 10;
	int b = 20;
	char c = 'c';
	//cout << myPlus(a, b) << endl;
	//cout << myPlus2(a, b) << endl;
	cout << myPlus<int>(a, c) << endl;//模板无法隐式转换，只能显示转换
	cout << myPlus2(a, c) << endl;

}
void test2() {
	int a = 10;
	int b = 20;
	myPrint<int>(a, b);
	myPrint(a, b, 10);
	myPrint(a, b);
	char c1 = 'c';
	char c2 = 'd';
	myPrint(c1, c2);
}
class Person {
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(Person& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		else return false;
	}
	string m_Name;
	int m_Age;
};
template<typename T>
bool myCompare(T& a, T& b) {
	return a == b;
}
template<> bool myCompare(Person& p1, Person& p2) {//模板函数具体化，也是模板，并非实例化
	cout << "具体化调用了..." << endl;
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age) {
		return true;
	}
	else return false;
}
template<typename N,typename A = int>//模板参数可以指定默认值（数据类型）
class Person1 {
public:
	Person1(N name, A age) {
		this->m_Age = age;
		this->m_Name = name;
	}
	void showPerson() {
		cout << "姓名：" << this->m_Name << ",年龄：" << this->m_Age << endl;
	}
	N m_Name;
	A m_Age;
};
template<typename T>//类模板中的成员函数并不是一开始创建，而是在使用时才生成(在替换T后生成)
class testClass {
public:
	void func1() {
		obj.show1();
	}
	void func2() {
		obj.show2();
	}
	T obj;
};
class Person2 {
public:
	void show1() {
		cout << "show1" << endl;
	}
};
class Person3 {
public:
	void show2(){
		cout << "show2" << endl;
	}
};
template<class T1,class T2>
class Person4 {
public:
	Person4(T1 name, T2 age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson4(){
		cout << "姓名：" << this->m_Name << ",年龄：" << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;

};
void doWork(Person4<string, int>& p) {//类模板做参数，1.指定具体类型  效率最高
	p.showPerson4();
}
template<class T1, class T2>
void doWork1(Person4<T1, T2>& p) {//2.函数模板，参数模板化
	cout << "T1 = " << typeid(T1).name() << endl;
	cout << "T2 = " << typeid(T2).name() << endl;
	p.showPerson4();
}
template<typename T>
void doWork2(T& p) {//3.函数模板，数据类型模板化  最简洁
	cout << "T = " << typeid(T).name() << endl;
	p.showPerson4();
}
void test3() {
	Person4<string, int>p("Tom", 20);
	doWork(p);
	doWork1(p);
	doWork2(p);
}
template<typename T>
class Base {// Base<double>
public:
	T m_A;
};
class Son : public Base<int> {// 继承模板：1.指定数据类型
};
template<typename T1,typename T2>// 2.子类模板继承
class Son1 : public Base<T2> {// Son1<int,double>
public:
	Son1() {
		cout << "T1 = " << typeid(T1).name() << endl;
		cout << "T2 = " << typeid(T2).name() << endl;
	}
	T1 m_A;
};
template<typename T1, typename T2>
class Person5 {
public:
	Person5(T1 name, T2 age);
	void showPerson5();
	T1 m_Name;
	T2 m_Age;
};
template<typename T1, typename T2>
Person5<T1,T2>::Person5(T1 name, T2 age){
	this->m_Name = name;
	this->m_Age = age;
}
template<typename T1, typename T2>
void Person5<T1, T2>::showPerson5() {
	cout << "姓名：" << this->m_Name << ",年龄：" << this->m_Age << endl;
}
template<typename T1, typename T2>class Person7;
template<typename T1, typename T2>void printPerson7(Person7<T1, T2>& p);
template<typename T1, typename T2>
void print2Person7(Person7<T1, T2>& p) { // 类外实现
	cout << "姓名：" << p.m_Name << ",年龄：" << p.m_Age << endl;
}
template<typename T1, typename T2>
class Person7 {
	/*friend void printPerson7(Person7<T1, T2>& p) { // 类内实现
		cout << "姓名：" << p.m_Name << ",年龄：" << p.m_Age << endl;
	}*/
	friend void printPerson7<>(Person7<T1, T2>& p);
	friend void print2Person7<>(Person7<T1, T2>& p);
public:
	Person7(T1 name, T2 age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson7() {
		cout << "姓名：" << this->m_Name << ",年龄：" << this->m_Age << endl;
	}
private:
	T1 m_Name;
	T2 m_Age;
};
template<typename T1, typename T2>
void printPerson7(Person7<T1, T2>& p) { // 类外实现
	cout << "姓名：" << p.m_Name << ",年龄：" << p.m_Age << endl;
}
class Person8 {
public:
	Person8() {
		this->m_Age = 0;
		this->m_Name = " ";
	}
	Person8(string name,int age) {
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;
};

int main() {
	//int x = 10, y = 20;
	//mySwap(x, y);//自动类型推导 int
	//cout << "x = " << x << ", y = " << y << endl; // 输出: x = 20, y = 10
	//char c = 'A', d = 'B';
	//mySwap(c, d);
	//cout << "c = " << c << ", d = " << d << endl; // 输出: c = B, d = A
	//mySwap<int>(x, y); // 显式指定类型为 int
	//func<int>(); // 调用模板函数必须指定类型参数

	/*char chs[] = { 'd','c','b','a' };
	int len = sizeof(chs) / sizeof(char);
	mySort(chs, len);
	printArr(chs, len);
	int arr[] = { 10,15,8,6,33,17,28 };
	int len1 = sizeof(arr) / sizeof(int);
	mySort(arr, len1);
	printArr(arr, len1);*/

	//函数模板和普通函数的区别以及调用机制
	/*
		普通函数与函数模板的调用规则：
		1.C++编译器优先考虑普通函数
		2.强制使用模板，需要加上空模板参数列表
		3.函数模板可以重载
		4.如果函数模板可以产生更好的匹配，优先使用函数模板
		5.编译器会对函数模板进行两次编译，在声明的地方对模板代码本身进行一次编译，在调用的地方对参数替换后的代码进行二次编译
	*/

	//test2();

	//函数模板机制和局限性
	
	/*int a = 10;
	int b = 20;
	bool ret;
	cout << myCompare(a, b) << endl;
	Person p1("Tom", 10);
	Person p2("Jerry", 20);
	cout << myCompare(p1, p2) << endl;*/
	
	//模板并不是真正的通用，对于特殊的数据类型，可以具体化实现解决问题，语法：template<>返回值类型 函数名 （参数列表）{} Person

	//类模板的基础语法及类模板中成员函数的创建时机 Person1

	//Person1<string, int> p1("Tom", 20);//使用类模板，只能显式指定类型
	//p1.showPerson();
	//Person1<string>p2("Tom", 20);
	//p2.showPerson();
	//testClass<Person3>tc;
	//tc.func2();

	//类模板做函数参数 Person4 

	//test3();

	//类模板再继承中的问题及解决方案 Base Son指定数据类型 Son1子类模板继承

	/*Son1<int, double>s;
	cout << "Base = " << typeid(Base<double>).name() << endl;
	cout << "Son1 = " << typeid(Son1<int,double>).name() << endl;*/

	//类模板成员函数类内和类外实现，类外实现链接前不生产成员函数，故把实现写在.h文件里 Person5 Person6

	//Person5<string, int>p("zs", 20);
	//p.showPerson5();
	//Person6<string, int>p1("zs", 20);// 无法解析的外部符号 链接阶段出现问题
	//p1.showPerson6();

	//类模板与友元 当友元函数类外实现时，类内修改为模板，实现需要写在类模板之前，实现之前需要声明类模板，或者实现写在类模板之后，但要在类模板前声明，且声明之前需要声明类模板

	//Person7<string, int> p("Tom", 21);
	//printPerson7(p);
	//print2Person7(p);

	//模板案例-数组类封装

	MyArray<int>intArray(10);
	for (int i = 0; i < 10; i++) {
		intArray.push_Back(i + 100);
	}
	for (int i = 0; i < intArray.getSize(); i++) {
		cout << intArray[i] << endl;
	}
	cout << "=====================" << endl;
	MyArray<Person8>personArray(10);
	Person8 p1("aaa", 10);
	Person8 p2("bbb", 20);
	Person8 p3("ccc", 30);
	Person8 p4("aaa", 40);
	Person8 p5("aaa", 50);
	personArray.push_Back(p1);
	personArray.push_Back(p2);
	personArray.push_Back(p3);
	personArray.push_Back(p4);
	personArray.push_Back(p5);
	for (int i = 0; i < personArray.getSize(); i++) {
		cout << "姓名：" << personArray[i].m_Name << "，年龄："<< personArray[i].m_Age << endl;
	}


	return 0;
}