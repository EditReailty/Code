#include <iostream>
#include "Student.h"
#include "Cube.h"
#include "Point.h"
#include "Circle.h"
#include "Person.h"
#include "List.h"
#include "MyArray.h"
#include "MyString.h"
using namespace std;

class Phone {
public:
	string m_Phone;
	// 构造函数
	Phone() {
		cout << "Phone的无参构造函数" << endl;
	}
	Phone(string phone) : m_Phone(phone) {
		cout << "Phone的有参构造函数" << endl;
	}
	~Phone() {
		cout << "Phone的析构函数" << endl;
	}
};
class Game {
public:
	string m_Game;
	//构造函数
	Game() {
		cout << "Game的无参构造函数" << endl;
	}
	Game(string game) : m_Game(game) {
		cout << "Game的有参构造函数" << endl;
	}
	~Game() {
		cout << "Game的析构函数" << endl;
	}
};
class person {
public:
	string m_Name;
	Phone m_Phone; // 假设Phone是一个类，表示手机信息
	Game m_Game; // 假设Game是一个类，表示游戏信息
	// 构造函数
	person() {
		cout << "Person的无参构造函数" << endl;
	}
	person(string name, string phone, string game)
		: m_Name(name), m_Phone(phone), m_Game(game) {
		cout << "Person的有参构造函数"<< endl;
	}
	~person() {
		cout << "Person的析构函数" << endl;
	}
};
class person1 {
public:
	int m_A;
	static int m_B; // 静态成员变量，在类中声明，但在类外定义和初始化

	static void fun() {
		//m_A = 10; 静态成员函数不能访问非静态成员变量
		m_B = 200;
		cout << "静态成员函数被调用了" << endl;
	}
	void fun1() {
		m_A = 100; // 非静态成员函数可以访问非静态成员变量
		m_B = 300; // 非静态成员函数可以访问静态成员变量
		cout << "m_A: " << m_A << ", m_B: " << m_B << endl;
	}
};
int person1::m_B = 10; // 静态成员变量的定义和初始化m_B = 10; // 静态成员变量的定义和初始化
class ChairMan {
private:
	//1. 私有化构造函数，防止外部创建对象
	ChairMan() {                             
		cout << "ChairMan的构造函数" << endl;
	}
	ChairMan(const ChairMan& c) {
	
	}
	//2.创建一个静态的成员变量，用于存储单例对象的指针
	static ChairMan* singleMan;
public:
	//3.提供一个公共的静态方法，用于获取单例对象的指针
	static ChairMan* getInstance() {
		//return singleMan;//饿汉式
		if (singleMan == nullptr) { // 懒汉式
			singleMan = new ChairMan; // 如果单例对象不存在，则创建一个新的对象
		}
		return singleMan; // 返回单例对象的指针
	}
};
//ChairMan* ChairMan::singleMan = new ChairMan; // 静态成员变量初始化为单例对象，饿汉式
ChairMan* ChairMan::singleMan = nullptr;
class Building;
class GoodFriend {
public:
	void visit(Building& building);
	void visit1(Building& building);
};
class Building {
	//friend class GoodFriend; //让GoodFriend类成为Building类的友元类，这样就可以访问Building类的私有成员变量。
	friend void GoodFriend::visit1(Building& building); //让GoodFriend类的visit1方法成为Building类的友元函数，这样就可以访问Building类的私有成员变量。
	friend void visit0(Building& building);//让全局函数visit成为Building类的友元函数，这样就可以访问Building类的私有成员变量。
public:
	string m_SittingRoom;

	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
private:
	string m_BedRoom;
};
void visit0(Building& building) {
	// 访问Building类的私有成员变量
	cout << "正在访问：" << building.m_SittingRoom << endl;
	cout << "正在访问：" << building.m_BedRoom << endl; // 不能访问私有成员变量 
}
void GoodFriend::visit(Building& building) {
	// 访问Building类的私有成员变量
	cout << "正在访问：" << building.m_SittingRoom << endl;
	//cout << "正在访问：" << building.m_BedRoom << endl; // 可以访问私有成员变量
}
void GoodFriend::visit1(Building& building) {
	// 访问Building类的私有成员变量
	cout << "正在访问：" << building.m_SittingRoom << endl;
	cout << "正在访问：" << building.m_BedRoom << endl; // 可以访问私有成员变量
}
class Time {
public:
	int m_Hour; // 小时
	int m_Minute; // 分钟
	// 构造函数
	Time() : m_Hour(0), m_Minute(0){ // 无参构造函数，默认时间为00:00:00
		cout << "时间的无参构造函数" << endl;
	}
	Time(int hour, int minute) : m_Hour(hour), m_Minute(minute) {
		cout << "时间的构造函数" << endl;
	}
	// 析构函数
	~Time() {
		cout << "时间的析构函数" << endl;
	}
	void addHour(int h) {
		m_Hour += h;
	}
	void addMin(int m) {
		m_Minute += m;
		m_Hour += m_Minute / 60;
		m_Minute = m_Minute % 60;
	}
	void reset(int h, int m) {
		m_Hour = h;
		m_Minute = m;
	}
	void show() {
		cout << "hours = " << m_Hour << ",minute = " << m_Minute << endl;
	}
	Time sum(Time& t) const{
		Time result;
		result.m_Hour = this->m_Hour + t.m_Hour;
		result.m_Minute = this->m_Minute + t.m_Minute;
		result.m_Hour += result.m_Minute / 50; // 处理分钟超过60的情况
		result.m_Minute = result.m_Minute % 60; // 保持分钟在0-59之间
		return result;
	}
	Time operator+(const Time& t) const {
		Time result;
		result.m_Hour = this->m_Hour + t.m_Hour;
		result.m_Minute = this->m_Minute + t.m_Minute;
		result.m_Hour += result.m_Minute / 60; // 处理分钟超过60的情况
		result.m_Minute = result.m_Minute % 60; // 保持分钟在0-59之间
		return result;
	}
};
//static Time operator+(Time& t1,Time& t2) {
//	Time result;
//	result.m_Hour = t1.m_Hour + t2.m_Hour;
//	result.m_Minute = t1.m_Minute + t2.m_Minute;
//	result.m_Hour += result.m_Minute / 60; // 处理分钟超过60的情况
//	result.m_Minute = result.m_Minute % 60; // 保持分钟在0-59之间
//	return result;
//}
class Person2 {
friend ostream& operator<<(ostream& os, Person2& p);
private:
	int m_A;
	int m_B;
public:
	Person2(int a, int b) : m_A(a), m_B(b) {
		cout << "Person的有参构造函数" << endl;
	}
};
ostream& operator<<(ostream& os, Person2& p) {
	os << "m_A: " << p.m_A << ", m_B: " << p.m_B ;
	return os;
}
class Myint {
	friend ostream& operator<<(ostream& os, Myint m) {//前置++：ostream& operator<<(ostream& os, Myint& m)
		os << "num: " << m.num;
		return os;
	}
public:
	Myint(): num(0) {
	}
	Myint& operator++() { // 前置++，返回类型为Myint&，表示返回当前对象的引用
		num++;
		return *this; // 前置++
	}
	Myint operator++(int) { // 后置++
		Myint temp = *this; // 保存当前状态
		num++;
		return temp; // 返回之前的状态
	}
private:
	int num;

};
class Person3 {
public:
	Person3(int age) {
		cout << "Person3的有参构造函数" << endl;
		m_Age = age;
	}
	void showAge() const {
		cout << "Age: " << this->m_Age << endl;
	}
	int m_Age;
	~Person3() {
		cout << "Person3的析构函数" << endl;
	}
};
//智能指针
class SmartPointer {
public:
	Person3* operator->() { // 重载->运算符，返回指向Person3对象的指针
		return m_Person;
	}
	Person3& operator*() { // 重载*运算符，返回Person3对象的引用
		return *m_Person;
	}
	SmartPointer(Person3* person) : m_Person(person) {
		cout << "SmartPointer的构造函数" << endl;
	}
	~SmartPointer() {
		if (m_Person != nullptr) {
			delete m_Person; // 释放Person3对象的内存
			m_Person = nullptr; // 避免悬空指针
			cout << "SmartPointer的析构函数" << endl;
		}
	}
private:
	Person3* m_Person; // 指向Person3对象的指针
};
class Person4 {
public:
	char* m_Name = nullptr;
	Person4& operator=(const Person4& p) { // 重载赋值运算符
		if (this != &p) { // 防止自赋值
			if (m_Name != nullptr) {
				delete[] m_Name; // 释放原有内存
			}
			m_Name = new char[strlen(p.m_Name) + 1]; // 分配新的内存
			strcpy(m_Name, p.m_Name); // 复制字符串
		}
		return *this; // 返回当前对象的引用
	}
	Person4() {
		cout << "Person4的无参构造函数" << endl;
	}
	Person4(const char* name) {
		cout << "Person4的有参构造函数" << endl;
		m_Name = new char[strlen(name) + 1]; // 分配内存
		strcpy(m_Name, name); // 复制字符串
	}
	// 拷贝构造函数
	Person4(const Person4& p) {
		cout << "Person4的拷贝构造函数" << endl;
		if (p.m_Name != nullptr) {
			m_Name = new char[strlen(p.m_Name) + 1]; // 分配新的内存
			strcpy(m_Name, p.m_Name); // 复制字符串
		}
		else {
			m_Name = nullptr; // 如果源对象的名字为空，则设置为nullptr
		}
	}
	~Person4() {
		if (m_Name != nullptr) {
			delete[] m_Name; // 释放内存
			m_Name = nullptr; // 避免悬空指针
			cout << "Person4的析构函数" << endl;
		}
	}
};
class Person5 {
public:
	Person5(const string& name, int age) {//常量引用作函数参数，避免不必要的拷贝
		cout << "Person5的有参构造函数" << endl;
		this->m_Name = name; // 使用初始化列表初始化成员变量
		this->m_Age = age;
	}
	bool operator==(const Person5& other) const { // 重载==运算符
		return (this->m_Name == other.m_Name && this->m_Age == other.m_Age);
	}
	bool operator!=(const Person5& other) const { // 重载!=运算符
		return !(*this == other); // 使用==运算符的结果
	}
	bool operator<(const Person5& other) const { // 重载<运算符
		return (this->m_Age < other.m_Age); // 比较年龄
	}
	string m_Name;
	int m_Age;

};
class MyPrint {
public:
	//重载()运算符
	void operator()(string text) {
		cout << "MyPrint: " << text << endl;
	}
};
class MyAdd {
	public:
	//重载()运算符
	int operator()(int a, int b) {
		return a + b; // 返回两个整数的和
	}
};
static void test1() {
	MyString str = "MyString Class";
	cout << str << endl; // 使用<<重载输出字符串
	MyString str2 = str; // 使用拷贝构造函数
	cout << str2 << endl; // 输出拷贝的字符串
	cout << "字符串长度: " << str2.length() << endl; // 输出字符串长度
	cin >> str2; // 使用>>重载输入字符串
	cout << "输入的字符串: " << str2 << endl; // 输出输入的字符串
}
static void test2() {
	MyString s1 = "abc";
	MyString s2 = "def";
	MyString s3 = s1 + s2;
	MyString s4 = s3 + "ghi"; // 使用+运算符连接字符串
	cout << s3 << endl;
	cout << s4 << endl;
	MyString s5 = "hello" + s1;
	cout << s5 << endl; // 使用+运算符连接字符串和C风格字符串
}
static void test3() {
	MyString s1 = "abc";
	MyString s2 = "def";
	s1 = s2;
	s2 = "ghi";
	cout << s1 << endl;
	cout << s2 << endl; // 输出字符串s1和s2
}
static void test4() {
	MyString s1 = "abcdef";
	cout << s1[3] << endl;
	s1[3] = 'z';
	cout << s1 << endl;
}
static void test5() {
	MyString s1 = "abc";
	MyString s2 = "abcd";
	cout << (s1 == s2) << endl; // 使用==运算符比较字符串
	cout << (s2 == "abcd") << endl; // 使用==运算符比较字符串和C风格字符串
}
static void test6() {
	MyString s1 = "abc";
	s1 += "def"; // 使用+=运算符连接字符串
	cout << s1 << endl; // 输出连接后的字符串
	MyString s2 = "ghi";
	s1 += s2; // 使用+=运算符连接字符串
	cout << s1 << endl; // 输出连接后的字符串
	cout << s2 << endl; // 输出字符串s2
}
class MyString2 {
public:
	//被explicit修饰的构造函数，表示只能通过显式调用来创建对象，不能进行隐式转换
	explicit MyString2(int len) {
		cout << "MyString2的有参构造函数 MyString2(int len)" << endl;
	}
	MyString2(const char* str) {
		cout << "MyString2的有参构造函数 MyString2(const char* str)" << endl;
	}
	//转换函数
	operator double() {
		return 3.14; // 将MyString2转换为double类型
	}
};
class Person6 {
public:
	string name;
	int age;
	void eat() {
		cout << "吃饭" << endl;
	}
	void sleep() {
		cout << "睡觉" << endl;
	}
};
class Student1 :public Person6 {
public:
	void study() {
		cout << "学习" << endl;
	}
};
class Teacher :public Person6{
public:
	void teach() {
		cout << "教课" << endl;
	}
};
class Fu {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;

};
class Zi : public Fu {
public:
	void func() {
		m_A = 10; // 可以访问基类的公有成员
		m_B = 20; // 可以访问基类的保护成员
		// m_C = 30; // 错误，不能访问基类的私有成员
		cout << "m_A: " << m_A << ", m_B: " << m_B << endl;
	}
};
class Base {
public:
	int m_A;
	void func() {
		cout << "Base func" << endl;
	}
protected:
	int m_B;
private:
	int m_C;
};
class Son : public Base {
public:
	int m_D;
};
class Base1 {
public:
	Base1(){
		cout << "Base1的构造函数" << endl;
	}
	~Base1() {
		cout << "Base1的析构函数" << endl;
	}
};
class other {
public:
	other() {
		cout << "other的构造函数" << endl;
	}
	~other() {
		cout << "other的析构函数" << endl;
	}
};
class Son1 : public Base1 {
	public:
	Son1() {
		cout << "Son1的构造函数" << endl;
	}
	~Son1() {
		cout << "Son1的析构函数" << endl;
	}
	other m_Other; // 成员变量other
};
class Base2 {
public:
	
	Base2(int a) {
		this->m_A = a;
		cout << "Base2的有参构造函数" << endl;
	}
	~Base2() {
		cout << "Base2的析构函数" << endl;
	}
	int m_A;
};
class Son2 : public Base2 {
public:
	Son2() :Base2(10){
		cout << "Son2的无参构造函数" << endl;
	}
	Son2(int b) :Base2(b){
		this->m_B = b;
		cout << "Son2的有参构造函数" << endl;
	}
	~Son2() {
		cout << "Son2的析构函数" << endl;
	}
	int m_B;
};
class Base3 {
public:
	Base3() {
		this->m_A = 10;
		cout << "Base3的构造函数" << endl;
	}
	void func() {
		cout << "Base3的func函数" << endl;
	}
	void func(int a) {
		cout << "Base3的func函数，参数为: " << a << endl;
	}
	int m_A;
};
class Son3 : public Base3 {
public:
	Son3() { 
		this->m_A = 20; // 初始化子类的成员变量
		cout << "Son3的构造函数" << endl;
	}
	void func() {
		cout << "Son3的func函数" << endl;
	}
	int m_A;
};
class Base4 {
public:
	static int m_A; // 静态成员变量，编译时就已经分配好了内存，类的所有对象共享同一份内存空间，类内声明，类外定义和初始化
	static void show() {
		cout << "Base4的静态成员函数，m_A: " << m_A << endl;
	}
	static void show(int a) {
		cout << "Base4的静态成员有参重载函数" << endl;
	}
};
int Base4::m_A = 10; // 静态成员变量的定义和初始化
class Son4 : public Base4 {
public:
	static int m_A;
	static void show() {
		cout << "Son4的静态成员函数，m_A: " << m_A << endl;
	}
};
int Son4::m_A = 20; // 静态成员变量的定义和初始化
class Base5 {
public:
	Base5() {
		cout << "Base5的构造函数" << endl;
		this->m_A = 10; // 使用this指针访问成员变量
	}
	void func() {
		cout << "Base5的func函数" << endl;
	}
	int m_A; // 成员变量
};
class Base6 {
public:
	Base6() {
		cout << "Base6的构造函数" << endl;
		this->m_A = 30; // 使用this指针访问成员变量
		this->m_B = 20; // 使用this指针访问成员变量
	}
	void func() {
		cout << "Base6的func函数" << endl;
	}
	int m_A;
	int m_B; // 成员变量
};
class Son5 : public Base5, public Base6 {
public:
	int m_C; // 子类的成员变量
	int m_D; // 子类的成员变量
};
class Person7 {
public:
	int m_age;
};
class Singer : virtual public Person7 {//Person7被称为虚基类

};
class Waiter : virtual public Person7 {

};
class SingingWaiter : public Singer, public Waiter {

};
class Animal {
public:
	//虚函数，动态联编 vfptr 虚函数表指针
	virtual void speak() {
		cout << "Animal speak" << endl;
	}
};
class Cat : public Animal {
public:
	void speak() { // 重写基类的speak方法
		cout << "Cat speak" << endl;
	}
};
class Dog : public Animal {
public:
	void speak() { // 重写基类的speak方法
		cout << "Dog speak" << endl;
	}
};
void doSpeak(Animal& animal) {
	animal.speak(); // 调用基类的speak方法
}
class Calculator {//开闭原则 对拓展开放，对修改关闭
public:
	int m_A;
	int m_B;
	//virtual int getResult(string oper) {
	//	if(oper == "+") {
	//		return m_A + m_B; // 返回加法结果
	//	}
	//	else if (oper == "-") {
	//		return m_A - m_B; // 返回减法结果
	//	}
	//	else if (oper == "*") {
	//		return m_A * m_B; // 返回乘法结果
	//	}
	//	else if (oper == "/") {
	//		if (m_B != 0) {
	//			return m_A / m_B; // 返回除法结果
	//		}
	//		else {
	//			cout << "除数不能为0" << endl;
	//			return 0; // 除数为0，返回0
	//		}
	//	}
	//	else {
	//		cout << "不支持的运算符" << endl;
	//		return 0; // 不支持的运算符，返回0
	//	}
	//}
	virtual int getResult() = 0; // 纯虚函数，要求子类必须实现
};
class AbstractCalculator {
public:
	int m_A;
	int m_B;
	virtual int getResult() {
		return 0;
	}
};
class AddCalculator : public AbstractCalculator {
public:
	virtual int getResult() {
		return m_A + m_B;
	}
};
class SubCalculator : public AbstractCalculator {
public:
	virtual int getResult() {
		return m_A - m_B;
	}
};
class MulCalculator : public AbstractCalculator {
public:
	virtual int getResult() {
		return m_A * m_B;
	}
};
class Base7 {//抽象类无法实例化
public:
	virtual void func() = 0;
	virtual void func1() {//可以共存
	}
};
class Son7 : public Base7 {//子类必须重写纯虚函数，否则也是抽象类
public:
	void func() override { // 重写基类的纯虚函数
		cout << "Son7的func函数" << endl;
	}
	//void func1() override { // 可以选择重写基类的虚函数
	//	cout << "Son7的func1函数" << endl;
	//}
};
class Animal1 {
public:
	Animal1() {
		cout << "Animal1的构造函数" << endl;
	}
	virtual void speak() = 0;
	//virtual ~Animal1() {// 虚析构函数，确保派生类的析构函数被调用
	//	cout << "Animal1的析构函数" << endl;
	//}
	virtual ~Animal1() = 0; // 纯虚析构函数，确保派生类的析构函数被调用，需要声明和实现，类外实现
};
Animal1::~Animal1() {
	cout << "Animal1的纯虚析构函数" << endl; // 类外实现纯虚析构函数，如果类中有了纯虚析构，则这个类就是抽象类，不能实例化
}
class Cat1 : public Animal1 {
public:
	Cat1(const char* name) {
		cout << "Cat1的构造函数" << endl;
		this->m_Name = new char[strlen(name)+1]; // 使用this指针访问成员变量	
		strcpy(this->m_Name, name); // 复制字符串
	}
	void speak() override {
		cout << this->m_Name << " :Cat1 speak" << endl;
	}
	~Cat1() {
		if(m_Name != nullptr) {
			delete[] m_Name; // 释放内存
			m_Name = nullptr; // 避免悬空指针
			cout << "Cat1的析构函数" << endl;
		}
	}
	char* m_Name;
};

int main() {
	//类的使用-对象 Student

	////创建学生对象
	//Student s1;
	////使用学生对象
	//s1.m_Name = "张三";
	//s1.m_Age = 20;
	//s1.m_Id = 1001;
	//cout << s1.m_Name << "\t" << s1.m_Age << "\t" << s1.m_Id << endl;
	////调用对象的方法
	//s1.sleep();
	//s1.eat();
	//s1.study();
	////动态创建
	//Student* s2 = new Student;
	//s2->m_Name = "李四";
	//cout << s1.m_Name << "\t" << s1.m_Age << "\t" << s1.m_Id << endl;

	//封装和访问控制

	//Student s1; //创建学生对象
	//s1.setName("张三"); //设置姓名
	//s1.setAge(20); //设置年龄
	//s1.setId(1001); //设置学号
	//cout << s1.getName() << "\t" << s1.getAge() << "\t" << s1.getId() << endl; //输出学生信息

	//立方体 Cube 

	//Cube c1;
	//c1.setLength(10); //设置长度
	//c1.setWidth(5);  //设置宽度
	//c1.setHeight(8); //设置高度
	//cout << "立方体的体积: " << c1.getVolume() << endl; //输出体积
	//cout << "立方体的表面积: " << c1.getArea() << endl; //输出表面积
	//Cube c2;
	//c2.setLength(9); //设置长度
	//c2.setWidth(4);  //设置宽度
	//c2.setHeight(7); //设置高度
	//bool result = c1.cubcompare(c2); //比较两个立方体
	//cout << result << endl;

	//圆和点 Circle Point

	//Point p;
	//p.setX(3); // 设置点的X坐标
	//p.setY(4); // 设置点的Y坐标
	//Circle c;
	//c.setCenter(0, 0); // 设置圆心坐标
	//c.setRadius(4); // 设置圆的半径
	//c.isPointInCircle(p); // 检查点是否在圆内或在圆上

	//构造函数：初始化 与 析构函数：销毁数据
	/*
	构造函数：
		1.构造函数名和类名相同
		2.没有返回值，不用void
		3.允许重载
	析构函数：
		1.析构函数和类名相同，前加上~
		2.没有返回值，不用void
		3.无参，不可以重载
	构造函数和析构函数是由编译器自动调用一次，无需手动调用，如果没有提供构造函数/析构函数，编译器会自动提供一个无参的、空实现的构造函数/析构函数
	构造函数的分类：
	    1.无参构造函数：没有参数的构造函数
		2.有参构造函数：有参数的构造函数
		3.拷贝构造函数：用一个对象初始化另一个对象时调用的构造函数
	构造函数的调用：1.显式调用 2.隐式调用
	      调用时机：1.创建对象时调用 2.函数返回对象时调用 3.函数参数传递对象时调用
	构造函数的调用规则：
	    默认情况下，C++编译器至少会为我们提供类的三个函数
		1.默认构造构造函数（无参构造函数，函数体为空）
		2.默认析构构造函数（无参析构函数，函数体为空）
		3.默认拷贝构造函数，对类中非静态成员属性进行简单的值的拷贝
	如果用户定义了普通的构造，C++不会提供默认无参构造，但会提供拷贝构造函数
	如果用户定义了拷贝构造函数，C++不会提供任何默认构造函数

	*/

	//Person p = Person();
	//Person p1("张三", 20);
	//cout << "姓名: " << p1.m_Name << ", 年龄: " << p1.m_Age << endl;
	//Person p2 = p1; // 使用拷贝构造函数
	//cout << "姓名: " << p2.m_Name << ", 年龄: " << p2.m_Age << endl;

	//深拷贝和浅拷贝

	//初始化列表（一种语法，用来对成员数据进行初始化）,一般是用来对const修饰的成员和引用类型的成员进行初始化 List

	////List l;
	//List l(1, 2, 3); // 使用有参构造函数初始化成员变量
	//cout << l.m_A << "\t" << l.m_B << "\t" << l.m_C << endl; // 输出成员变量A、B、C的值

	//类对象作为类成员

	//person p1("张三", "1234567890", "王者荣耀");
	
	//静态成员：不管类创建了多少个对象，静态成员只有一份，所有对象共享同一份数据/静态成员函数 person1

	//person1 p1;
	//cout << "p1.m_B: " << p1.m_B << endl; 
	//person1 p2;
	//cout << "p2.m_B: " << p2.m_B << endl; 
	//p2.m_B = 20; // 修改静态成员变量
	//cout << "p1.m_B: " << p1.m_B << endl; // 静态成员变量被修改
	//cout << person1::m_B << endl; // 直接通过类名访问静态成员变量
	//person1::fun(); // 调用静态成员函数
	
	//单例设计模式-单个对象、实例，程序员的经验总结。一个类在一个程序中只能有一个对象。好处：防止创建过多的对象，节省内存空间，避免资源浪费。 chairman

	//ChairMan* chairman = ChairMan::getInstance(); // 获取单例对象
	//ChairMan* chairman2 = ChairMan::getInstance(); // 再次获取单例对象
	//cout << (chairman == chairman2) << endl;
	//ChairMan* chairman3 = new ChairMan(*chairman); // 直接创建对象，违反单例模式，通过拷贝私有禁用
	//cout << (chairman == chairman3) << endl; // 输出0，说明不是同一个对象

	//this指针，用来指向调用成员函数的对象，谁调用方法，this就指向谁。this会被作为隐式参数传递给方法，每一个非静态的成员方法中都有this指针。
	//this的作用：1.当形参和成员变量同名时，可以用this指针来区分。2.在类的非静态成员方法中返回对象本身，可以用return*this

	//常函数和常对象
	/*
		在方法中对某个对象即让this指向的对象的内容不能被修改，即const Person* const this
		常函数：void show() const{}，在成员方法中不可修改成员变量的值（成员变量被mutable修饰除外）
		常对象：const Person p1;，在常对象中不可修改成员变量的值（成员变量被mutable修饰除外），常对象不能调用普通函数，可以调用常函数
	*/

	//友元 Goodfriend
	/*
	  友元有三种：
		1.友元（全局）函数
		2.友元类
		3.友元成员函数
	  注意事项：
		1.友元不能被继承
		2.友元关系是单向的
		3.友元关系不具有传递性
	*/
    
    //Building building;
	////cout << "正在访问：" << building.m_SittingRoom << endl;
	////cout << "正在访问：" << building.m_BedRoom << endl; // 不能访问私有成员变量	
	//visit0(building);
	//GoodFriend goodfriend;
	//goodfriend.visit(building); // 友元类可以访问私有成员变量
	//goodfriend.visit1(building); // 友元函数可以访问私有成员变量

	//数组封装案例 MyArray
	
	//MyArray arr1;
	//cout << "数组容量: " << arr1.getCapacity() << endl; // 输出数组容量
	//cout << "数组大小: " << arr1.getSize() << endl; // 输出数组大小
	//arr1.pushBack(10); // 添加数据到数组
	//arr1.pushBack(20); // 添加数据到数组
	//arr1.pushBack(30); // 添加数据到数组
	//arr1.pushBack(40); // 添加数据到数组
	//cout << "数组容量: " << arr1.getCapacity() << endl; // 输出数组容量
	//cout << "数组大小: " << arr1.getSize() << endl; // 输出数组大小
	//for (int i = 0; i < arr1.getSize(); ++i) {
	//	cout << "数组元素[" << i << "]: " << arr1.getData(i) << endl; // 输出数组元素
	//}
	//arr1.setData(2, 100); // 修改数组中指定位置的数据
	//cout << "=======================" << endl;
	//for (int i = 0; i < arr1.getSize(); ++i) {
	//	cout << "数组元素[" << i << "]: " << arr1.getData(i) << endl; // 输出数组元素
	//}
	//MyArray arr2(arr1); // 使用拷贝构造函数创建新数组
	//cout << "=======================" << endl;
	//for (int i = 0; i < arr2.getSize(); ++i) {
	//	cout << "数组元素[" << i << "]: " << arr2.getData(i) << endl; // 输出数组元素
	//}

    //运算符重载 operator overloading 是一种形态的C++多态
    //+重载 Time
	
    //Time t1(2, 30);
    ////t1.show(); // 显示初始时间
	//t1.addHour(1); // 增加1小时
	//t1.addMin(90); // 增加90分钟
	//t1.show(); // 显示修改后的时间
	//t1.reset(0, 0); // 重置时间为00:00	
	//t1.show(); // 显示重置后的时间
	//Time t1(2, 40);
	//Time t2(2, 30);
	////t1.sum(t2).show(); // 显示两个时间的和
	//Time t3 = t1 + t2;// 使用运算符重载
	//t3.show(); // 显示两个时间的和

    //<<重载 Person2

	//Person2 p(10, 20);
	////cout << "m_A: " << p.m_A << ", m_B: " << p.m_B << endl;
	//cout << p << endl;//operator<<(cout,p);operator<<(void,endl)

	//++重载 Myint  前置++，返回类型为Myint&，表示返回当前对象的引用  后置++，值返回，临时状态（原先状态）用过即毁

	//Myint m;
	//cout << m << endl;
	////cout << ++m << endl;// 前置++，返回类型为Myint&，表示返回当前对象的引用
	//cout << m++ << endl; // 后置++，值返回，临时状态（原先状态）用过即毁
	//cout << m << endl;

    //-> *重载 Person3
 
	//Person3* p = new Person3(20);
	//p->showAge(); // 调用成员函数显示年龄
	//(*p).showAge(); // 使用解引用操作符调用成员函数显示年龄
	////delete p; // 释放内存
	//SmartPointer sp(p); // 创建智能指针，自动管理Person3对象的内存
	//sp->showAge(); // sp.operatpror->() 返回指针Person3*，sp->->showAge();编译器会优化成sp->showAge();
	//(*sp).showAge(); // 返回Person3&，可以直接调用成员函数

	//赋值运算符重载 Person4 堆区动态创建数据且用到=，类比浅拷贝和深拷贝

	//Person4 p1("Tom");
	//Person4 p2;
	//Person4 p3("Jerry");
	//p1 = p2 = p3; // 使用赋值运算符重载
	//cout << "p1.m_Name: " << p1.m_Name << endl; // 输出p1的姓名
	//cout << "p2.m_Name: " << p2.m_Name << endl; // 输出p2的姓名
	//Person4 p4(p3);
	//cout << "p4.m_Name: " << p4.m_Name << endl; // 输出p4的姓名

    //[]重载 MyArray

    //MyArray arr(20);
    //arr.pushBack(10);
	//arr.pushBack(20);
	//arr.pushBack(30);
	//arr.pushBack(40);
	//for (int i = 0; i < arr.getSize(); ++i) {
	//	cout << "数组元素[" << i << "]: " << arr.getData(i) << endl;
	//	cout << "数组元素[" << i << "]: " << arr[i] << endl; // 使用[]重载访问数组元素
	//}
	//arr.setData(2, 100); // 修改数组中指定位置的数据
	//arr[2] = 200; // 使用[]重载修改数组中指定位置的数据
	//cout << "=======================" << endl;
	//for (int i = 0; i < arr.getSize(); ++i) {
	//	cout << "数组元素[" << i << "]: " << arr.getData(i) << endl;
	//	cout << "数组元素[" << i << "]: " << arr[i] << endl; // 使用[]重载访问数组元素
	//}

	//== != <重载 Person5

	//Person5 p1("Tom", 18);
	//Person5 p2("Tom", 18);
	//if (p1 == p2) {//p1.operator==(p2);  返回布尔类型，调用Person5类的引用
	//	cout << "p1和p2相等" << endl; // 使用==重载比较两个对象是否相等
	//}
	//else {
	//	cout << "p1和p2不相等" << endl; // 使用==重载比较两个对象是否相等
	//}
	//if (p1 != p2) { // 使用!=重载比较两个对象是否不相等
	//	cout << "p1和p2不相等" << endl;
	//}
	//else {
	//	cout << "p1和p2相等" << endl;
	//}
	//if (p1 < p2) { // 使用<重载比较两个对象的年龄
	//	cout << "p1的年龄小于p2的年龄" << endl;
	//}
	//else {
	//	cout << "p1的年龄不小于p2的年龄" << endl;
	//}

	//()重载  MyPrint MyAdd

	//MyPrint mp;
	//mp("Hello, World!"); // 使用()重载打印字符串,仿函数，本质上是对象而不是函数，该对象称之为函数对象
	//MyAdd ma;
	//int result = ma(10, 20); // 使用()重载计算两个整数的和
	//cout << "10 + 20 = " << result << endl; // 输出计算结果

	//运算符重载总结
	/*
		1.一元运算符（一个运算数），二元运算符（两个运算数）
		  ++ -- a++ ++a             t1 + t2
		2.成员运算符函数
		  一元没有参数 二元有一个参数 operator+（Time& t）；
		3.全局运算符函数
		  一元有一个参数 二元有两个参数 operator+(Time& t1, Time& t2)；
		4.运算符重载必须是C++有效的运算符，不能虚构一个新的符号
		5.不能违反运算符原来的句法和含义
		6.不能重载以下运算符：:: . .* ?: sizeof typeid
		7.只能通过成员函数重载的运算符：
		= () [] -> 
		<< >> 只能通过全局函数重载
		不要重载&&和||，因为它们是短路运算符，重载后会导致逻辑错误
	*/

    //封装字符串类 MyString
    
	//test1(); // 测试MyString类的功能
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();

	//类的自动类型转换和强制类型转换，使类对象转换成基本类型的数据，需要添加转换函数  MyString2
	//转换函数1.必须是类方法，2.不能有参数，3.返回值类型是要转换的类型，4.函数名是operator+要转换的类型
	//自动类型转换：基本数据类型赋值给类对象，调用构造函数进行转换，但被explicit修饰的构造函数不能进行自动类型转换
	//强制类型转换：类对象赋值给基本数据类型，调用转换函数进行转换

	//double d = 3.14;
	//int num1 = (int)d;
	//int num2 = int(d); // 强制类型转换
	//cout << "num1: " << num1 << ", num2: " << num2 << endl; // 输出转换后的整数值
	//MyString2 s2 = "Hello, World!"; // 创建MyString2对象，调用有参构造函数
	////MyString2 s3 = 10;
	//MyString2 s4(10); // 显式调用MyString2(int len)构造函数
	//double d = s2;//double d = (double)s2; // 调用转换函数，将MyString2对象转换为double类型
	//cout << "转换后的double值: " << d << endl; // 输出转换后的double值

	//继承，是面向对象的一大特征 Student1 Teacher Person6
	/*
		多个类中存在相同的属性和行为时，将这些内容抽取到一个单独的类中，
		那么多个类无需再定义这些属性和行为，只要继承那个类即可。
		继承的格式：class 子类名 : 继承方式 父类名{}；
		子类：也被称为派生类  父类：也被称为基类、超类
		继承的好处：
			1.代码复用：子类可以继承父类的属性和方法，减少代码重复
			2.扩展性：子类可以在父类的基础上增加新的属性和方法，扩展功能
			3.多态性：通过父类指针或引用调用子类对象的方法，实现多态
			4.维护性：父类的修改可以自动应用到所有子类，减少维护成本
		继承的弊端：
			1.增加了类之间的耦合度，子类依赖于父类的实现  高内聚，低耦合
			2.如果父类修改了属性或方法，可能会影响到所有子类
			3.继承层次过深会导致代码难以理解和维护
	*/
	
	//Student1 s;
	//s.study(); // 调用Student1类的study方法
	//s.eat();
	//s.age = 18; // 继承自Person6类的属性
	//cout << "学生年龄: " << s.age << endl; // 输出学生年龄
	//Teacher t;
	//t.teach(); // 调用Teacher类的teach方法

	//protected成员访问控制 Fu Zi
	/*
	1.public：公共成员，任何地方都可以访问
	2.private：私有成员，只能在类内部访问，外部无法访问
	3.protected：保护成员，子类可以访问，但外部无法访问
	4.访问控制的继承方式：
		1.public继承：基类的public成员和protected成员在子类中仍然是public和protected
		2.protected继承：基类的public成员和protected成员在子类中变为protected
		3.private继承：基类的public成员和protected成员在子类中变为private
	成员变量一般使用private，成员方法可以使用protected
	*/

	//Fu f;
	//f.m_A = 10; // 可以访问public成员
	////f.m_B = 20; // 错误，无法访问protected成员
	////f.m_C = 30; // 错误，无法访问private成员
	//Zi z;
	//z.m_A = 10; // 可以访问public成员
	//z.func(); // 调用Zi类的func方法，访问protected成员m_B

	//继承中的对象模型 Base Son
	//类中的成员变量和成员方法时分开存储的，对象中只保存了成员变量的信息。子类继承父类时，会包括父类中的私有成员变量，但编译器进行了保护。	
	/*
		通过Visual Studio的调试工具可以查看类对象的内存布局，观察继承关系和成员变量的存储方式。
		1.打开Developer Command Prompt for VS
		2.切换到项目盘，D:，切换到项目目录，cd D:
		3.dir
		4.cl /d1 reportSingleClassLayout类名 2577leii.cpp
	*/

	//cout << "Base类对象大小: " << sizeof(Base) << endl; // 输出Base类对象的大小 12
	//cout << "Son类对象大小: " << sizeof(Son) << endl; // 输出Son类对象的大小 16（包括私有成员变量m_C）

	//继承中的构造函数和析构函数 Base1 Son1 Base2 Son2
	/*
		创建子类对象时，先调用父类的构造函数，再调用子类的构造函数；销毁子类对象时，先调用子类的析构函数，再调用父类的析构函数。
		如果子类有其它类数据成员，则先调用父类的构造函数，再调用其它类的构造函数，最后调用子类的构造函数；销毁时则相反，先调用子类的析构函数，再调用其它类的析构函数，最后调用父类的析构函数。
		子类的构造函数必须调用父类的构造函数初始化，子类的构造函数会默认使用父类的默认构造函数对父类数据进行初始化。
		调用父类的构造函数是在调用子类构造函数之前，使用成员初始化列表完成的。
	*/

	//Son1 s;
	//Son2 s1(20);
	//cout << "Son2的m_A: " << s1.m_A << endl; // 输出Son2的m_A
	//cout << "Son2的m_B: " << s1.m_B << endl; // 输出Son2的m_B

	//继承中的非静态同名成员处理 Base3 Son3
	
	//Son3 s;
	//cout << "Son3的m_A: " << s.m_A << endl; // 输出Son3的m_A，如果子类和父类有同名成员变量，子类的成员变量会覆盖父类的成员变量
	//s.func(); // 调用Son3的func方法，输出Son3的func函数
	////通过子类对象访问父类中的同名非静态成员，需要加上作用域
	//cout << s.Base3::m_A << endl; // 输出Base3的m_A
	//s.Base3::func(); // 调用Base3的func方法，输出Base3的func函数
	////如果子类中出现了和父类同名的成员变量或成员函数，子类会覆盖父类的同名成员变量或成员函数。如果需要访问父类的同名成员，可以使用作用域运算符。
	//s.Base3::func(10); // 子类重定义父类的成员函数

	//继承中的静态同名成员处理 Base4 Son4

	//Son4 s;
	//cout << "Son4的m_A: " << s.m_A << endl; // 输出Son4的m_A，访问静态成员变量
	//cout << "Base4的m_A: " << Base4::m_A << endl; // 输出Base4的m_A，访问静态成员变量
	//s.show();
	//s.Base4::show();
	//s.Base4::show(10);
	//cout << Son4::m_A << endl;
	//cout << Base4::m_A << endl;
	//cout << Son4::Base4::m_A << endl;//第一个Son4表示访问Son4的成员，第二个Base4表示作用域
	//Son4::show(); // 调用Son4的静态成员函数
	//Base4::show(); // 调用Base4的静态成员函数
	//Son4::Base4::show(); // 调用Base4的静态成员函数，使用作用域运算符

	//多重继承（多继承） Base5 Base6 Son5
	/*
		一个类可以同时继承多个类，这种方式称为多重继承。
		语法：
		class 子类名 : 继承方式1 父类1, 继承方式2 父类2, ... {
			// 类体
		};
		注意事项：继承方式最好不要省略，如果省略默认是私有继承
		多继承是非常受争议的
	*/

	//Son5 s;
	//cout << "Son5的m_A: " << s.Base5::m_A << endl; // 访问Base5的成员变量
	//cout << "Son5的m_B: " << s.Base6::m_B << endl; // 访问Base6的成员变量
	//s.Base5::func(); // 调用Base5的func方法
	//s.Base6::func(); // 调用Base6的func方法
	//cout << sizeof(s) << endl; // 输出Son5对象的大小，包含Base5和Base6的成员变量

	//菱形继承和虚继承 Person7 Singer Waiter SingingWaiter
/*
	如果有两个子类继承了同一个基类，然后又有一个类同时继承这两个子类，这种情况称为菱形继承。
	菱形继承带来的问题：
		1.二义性：当子类对象调用基类成员时，编译器无法确定调用哪个基类的成员，导致二义性错误。解决：加上作用域
		2.重复继承：子类对象会包含基类的多个副本，浪费内存空间。解决：使用虚继承
	
*/

	//SingingWaiter sw;
	////问题1：访问同名成员产生二义性
	//sw.m_age = 20; // 设置SingingWaiter的年龄
	//sw.Singer::m_age = 25; // 设置SingingWaiter的年龄
	//sw.Waiter::m_age = 30; // 设置Waiter的年龄
	////问题2：继承了两份数据，浪费内存空间

	//虚继承的实现原理 Person7 Singer Waiter SingingWaiter
	/*
		vbptr：virtual base pointer，虚基类指针
		原理：只有一个唯一的成员，通过保存虚基类指针，指针指向虚基类表，表中保存了当前获取到唯一数据的偏移量。
	*/

	//SingingWaiter sw;
	//sw.m_age = 20; // 设置SingingWaiter的年龄
	////通过singer找到偏移量
	//cout << "Singer的偏移量："  << *((int*)*(int*)(&sw) + 1) << endl;//x86环境下才能正常运行
	//cout << "Waiter的偏移量：" << *((int*)*((int*)(&sw) +1)+ 1) << endl;//x86环境下才能正常运行
	//cout << *(int*)((char*)&sw + *((int*)*(int*)(&sw) + 1)) << endl; //char*实现单个字节移动，int*一次移动4个字节

	//抽象、继承、多态，这里是多态 Animal Cat Dog
/*
	编译时多态-静态多态-静态联编：函数重载、运算符重载、模板
	运行时多态-动态多态-动态联编：继承（派生类）、虚函数
	虚函数：在基类中声明为virtual的成员函数，子类可以重写该函数，实现多态。
*/	

	//Cat c;
	////c.speak();
	//Dog d;
	////c.speak();
	////调用了基类的speak，属于静态联编，但是我们希望调用谁用谁的，动态联编，虚函数
	//doSpeak(c); // 调用doSpeak函数，传入Cat对象，输出Cat speak,C++中父类的引用指向子类对象不会报错
	//doSpeak(d); // 调用doSpeak函数，传入Dog对象
	//Animal& a = c; // 父类引用指向子类对象，多态
	//doSpeak(a); // 调用doSpeak函数，传入Animal引用，输出Cat speak

	//Cat c;
	//cout << sizeof(Animal) << endl; // 输出Animal类对象的大小
	////Animal* animalPtr = new Cat(); // 父类指针指向子类对象，Cat类被完整创建，多态

	//多态的案例（计算器类）Calculator AbstractCalculator AddCalculator SubCalculator MulCalculator

	/*AbstractCalculator* cal = new AddCalculator;
	cal->m_A = 10;
	cal->m_B = 20;
	cout << cal->getResult() << endl;	
	delete cal;
	cal = new SubCalculator;
	cal->m_A = 20;
	cal->m_B = 10;
	cout << cal->getResult() << endl;*/

	//纯虚函数和抽象类 Base7 Son7
	/*
		当类中有了纯虚函数，这个类属于抽象类，不能直接创建对象，只能通过继承该类的子类来实现具体的功能。
	
	*/

	//虚析构和纯虚析构 Animal1 Cat1
	
	Animal1* cat = new Cat1("Tom");
	cat->speak(); // 调用Cat1的speak方法
	delete cat; // 删除cat对象，调用Cat1的析构函数和Animal1的析构函数

	return 0;
}