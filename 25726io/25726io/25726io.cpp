#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<fstream>
#include<string>

using namespace std;

class Animal{
	virtual void eat(){}
	
};
class Dog :public Animal{
	virtual void eat() {//重写虚函数
		cout << "吃狗粮" << endl;
	}
};
class Other{};

void test1() {
	//char a = 'a';
	//double b = static_cast<double>(a);
	//cout << b << endl;
	//double d = 3.14;
	//int i = static_cast<int>(d);
	//cout << i << endl;
	Animal* animal = nullptr;
	Dog* dog = nullptr;
	Animal* anmial1 = static_cast<Animal*>(dog);//子类转父类 安全
	Dog* dog1 = static_cast<Dog*>(animal);//父类转子类 不安全 如Animal* animal = Cat(); Cat类转成Dog类
}
void test2() {
	Animal animal;
	Dog dog;
	Animal& ref_ani = animal;
	Dog& ref_dog = dog;
	Animal& ref_ani1 = static_cast<Animal&>(ref_dog);
	Dog& ref_dog1 = static_cast<Dog&>(ref_ani);
	Other* other = nullptr;
	//static_cast<Dog&>(other);// 没有继承关系的转换无效
}
void test3() {
	Animal* animal = new Animal();
	Dog* dog = new Dog();
	Animal* animal1 = dynamic_cast<Animal*>(dog);
	//dynamic_cast<Dog*>(animal);//下行转换需要多态
	Animal* animal2 = new Dog();
	dynamic_cast<Dog*>(animal2);//如果发生多态（重写虚函数）则可以向下转型
	Dog dog1;
	Dog& ref_dog1 = dog1;
	dynamic_cast<Animal&>(ref_dog1);
	Animal animal3;
	Animal& ref_ani = animal3;
	dynamic_cast<Dog&>(ref_ani);//发生多态，引用也可以转换
}
void test4() {
	const int* p = nullptr;
	int* np = const_cast<int*>(p);
	int* pp = nullptr;
	const int* npp = const_cast<const int*>(pp);
	int num = 10;
	int& ref_num = num;
	const int& refNum2 = const_cast<const int&>(ref_num);
	int& refNum3 = const_cast<int&>(refNum2);
}
void test5() {
	int a = 10;
	//int* p = reinterpret_cast<int*>(a);
	Animal* ap = new Animal();
	Other* op = reinterpret_cast<Other*>(ap);
}
class myException {
public:
	void printError() {
		cout << "我自己的异常" << endl;
	}
};
int myDived(int a, int b) {
	if (b == 0) {
		//通过throw抛出异常
		//throw 1;
		//throw 3.14;
		//throw string("aaa");
		//throw myException();
		throw 'a';
	}
	return a / b;
}
class Person {
public:
	Person(string name) {
		this->m_Name = name;
		cout << m_Name << "对象被创建！" << endl;
	}
	~Person() {
		cout << m_Name << "对象被析构！" << endl;
	}

	string m_Name;
};
void test6() {
	Person p1("aaa");
	Person p2("bbb");
	throw 10;
	Person p3("ccc");
}
void test7() {
	Person p4("ddd");
	test6();
}
class MyException {
public:
	MyException() {
		cout << "异常变量的构造函数" << endl;
	}
	MyException(const MyException& e) {
		cout << "拷贝构造" << endl;
	}
	~MyException() {
		cout << "异常变量析构函数" << endl;
	}
	void show() {
		cout << "捕获成功" << endl;
	}
};
void doWork() {
	throw MyException();
}
void test8() {
	try {
		doWork();
	}
	catch (MyException& e) {
		e.show();
	}
}
class BaseException {
public:
	virtual void printError() {}
};
class NullPointerException : public BaseException {
public:
	virtual void printError() {
		cout << "空指针异常！" << endl;
	}
};
class OutOfRangeException :public BaseException {
public:
	virtual void printError() {
		cout << "越界异常！" << endl;
	}
};
void doWork1() {
	//throw NullPointerException();
	throw OutOfRangeException();
}
class myOutOfRangeException :public exception {
public:
	myOutOfRangeException(const char* errInfo) {// string m_error = const char* errInfo 调用string类的构造，隐式转换，const char* errInfo = "Hello" 数组退化为指针，赋值
		this->m_error = errInfo;
	}
	myOutOfRangeException(string errInfo) {
		this->m_error = errInfo;
	}
	virtual ~myOutOfRangeException()noexcept {}
	virtual char const* what()const {
		return this->m_error.c_str();// string不能直接转换到const char*，需要调用c_str()
	}

	string m_error;

};
class Person1 {
public:
	Person1(int age) {
		if (age < 0 || age >= 150) {
			//throw out_of_range("年龄越界，必须在0~150之间");
			throw myOutOfRangeException("年龄越界，必须在0~150之间");
		}
		this->m_Age = age;
		cout << m_Age << "对象被创建！" << endl;
	}

	int m_Age;
};
void test9() {
	//char chs = cin.get();
	//cout << "chs = " << chs << endl;
	//chs = cin.get();
	//cout << "chs = " << chs << endl;
	//char chs;
	//cin.get(chs);
	//cout << "chs = " << chs << endl;

	//char buf[1024] = { 0 };
	//cin.get(buf, sizeof(buf));
	//cout << buf << endl;
	//char ch = cin.get();
	//if (ch == '\n') {
	//	cout << "换行符遗留在缓冲区中" << endl;
	//}
	//else {
	//	cout<<  "换行符未遗留在缓冲区" << endl;
	//}
	//char buf1[1024] = { 0 };
	//cin.get(buf1, sizeof(buf1));
	//cout << buf1 << endl;

	//char buf[1024] = { 0 };
	//cin.getline(buf, sizeof(buf));// 换行符不遗留
	//char ch = cin.get();

	//cin.ignore(3); //默认是忽略一个缓冲区中的字符
	//char ch = cin.get();
	//cout << ch << endl;

	//char ch = cin.peek();// 查看缓冲区中的第一个字符，并不会取值
	//cout << ch << endl;
	//ch = cin.get();
	//cout << ch << endl;

	//char ch = cin.get();
	//cin.putback(ch); //将ch放回原位
	//cin.get();
	//char buf[1024] = { 0 };
	//cin.getline(buf, sizeof(buf));
	//cout << ch <<"=="<< buf << endl;
	


}
void test10() {
	/*cout << "请输入一个字符串或数字：" << endl;
	char ch = cin.peek();
	if (ch >= '0' && ch <= '9') {
		int num;
		cin >> num;
		cout << "您输入的数字是：" << num << endl;
	}
	else {
		char buf[1024];
		cin >> buf;
		cout << "您输入的字符串是：" << buf << endl;
	}*/

	//int num;
	//while (1) {
	//	cout << "请输入1~10之间的数字：" << endl;
	//	cin >> num;
	//	//cout << cin.fail() << endl;//非int类型的非法字符读取失败需要重置标志位，清空缓冲区
	//	if (num >= 1 && num <= 10) {
	//		cout << "输入正确，输入的值为：" << num << endl;
	//		break;
	//	}
	//	cin.clear();//清空标志位
	//	char buf[1024] = {0};
	//	cin.getline(buf, sizeof(buf));

	}
void test11() {
	//cout.put('h').put('e');
	//char buf[] = "helloworld";
	//cout.write(buf, sizeof(buf));

	//int num = 99;
	//cout.width(10);
	//cout.fill('*');
	//cout.setf(ios::left);
	//cout.unsetf(ios::dec);
	//cout.setf(ios::hex);
	//cout.setf(ios::showbase);
	//cout.unsetf(ios::hex);
	//cout.setf(ios::oct);
	//cout << num << endl;

	//int number = 99;
	//cout << setw(20) << setfill('#') << setiosflags(ios::showbase) << setiosflags(ios::left) << hex << number << endl;
}
void test12() {
	////ofstream ofs("./test.txt", ios::out | ios::trunc);
	//ofstream ofs;
	//ofs.open("./test.txt", ios::out | ios::trunc);
	////判断对象是否打开成功
	//if (!ofs.is_open()) {
	//	cout << "文件打开失败" << endl;
	//	return;
	//}
	//ofs << "姓名：Tom" << endl;
	//ofs << "年龄：100" << endl;
	//ofs << "性别：男" << endl;
	//ofs.close();

	ifstream ifs;
	ifs.open("./test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	//char buf[1024] = { 0 };
	//while (ifs >> buf) { // while(ifs.getline(buf,sizeof(buf)))  
	//	cout << buf << endl;
	//}
	//string buf;
	//while (getline(ifs, buf)) {
	//	cout << buf << endl;
	//}
	char ch;
	while ((ch = ifs.get()) != EOF) {
		cout << ch;
	}
	ifs.close();
	
}
	

int main() {
	//静态转换 static_cast 语法：static_cast <typename>(expression) 基本类型转换、具有继承关系的类引用和指针的转换 Animal Dog Other

	//test1();
	//test2();

	//动态转换 dynamic_cast 仅能用于类层次间的上行转换和下行转换 上行转换与static_cast相同，下行转换具有类型检查的功能（多态），比静态安全 Animal Dog Other

	//常量转换与重新解释转换 常量转换const_cast：修改类型const的属性，也只能修改指针和引用 重新解释转换reinterpret_cast：最不安全的转换机制,也只能修改指针和引用

	//异常概述

	//myDived(10, 0);

	//异常的语法
	/*
		1.如果有异常可以通过throw操作创建一个异常对象并抛出
		2.将可能抛出异常的程序放到try代码块中
		3.如果没有异常，catch代码块就不会执行
		4.catch子句会根据出现的先后顺序被检查，匹配的catch语句捕获并处理异常（或继续抛出）
		5.如果匹配的处理未找到，则会中止程序
		6.处理不了的异常，可以在catch的最后一个分支，使用throw向上抛出
		7.C++的异常处理是的异常的引发和异常的处理不必在一个函数中，这样底层的函数可以着重解决具体问题，而不必过多考虑异常处理，上层的调用者可以在适当的位置设置对不同类型异常的处理
	*/

	//int a = 10, b = 0;
	//try {
	//	int ret = myDived(a, b);//把可能会异常的代码放到try块中
	//}
	//catch (int num) {//当捕捉到相应的异常后进行的处理代码
	//	cout << "int类型异常捕获：" << num << endl;
	//}
	//catch (double num) {
	//	cout << "double类型异常捕获：" << num << endl;
	//}
	//catch (string num) {
	//	cout << "string类型异常捕获：" << num << endl;
	//}
	//catch (myException e) {
	//	e.printError();
	//}
	//catch (...) {//其他类型的异常用...捕获
	//	cout << "其它类型异常捕获" << endl;
	//}

	//栈解旋 test6 test7
	/*
		栈解旋：异常被抛出以后，从进入try块起，到异常被抛掷前，这期间栈上构造的所有对象，都会被自动析构。栈解旋在进入catch块之前完成
		析构的顺序和构造的顺序相反，这一过程被称为栈的解旋。
	*/

	//try {
	//	test7();
	//}
	//catch (...) {
	//	cout << "异常被捕获" << endl;
	//}

	//异常变量的生命周期 MyException

	//test8();

	//异常的多态使用

	//try {
	//	doWork1();
	//}
	//catch (NullPointerException& e) {
	//	e.printError();
	//}
	//catch (OutOfRangeException& e) {
	//	e.printError();
	//}
	//catch (BaseException& e) { //引用产生多态，多态的好处可以接受子类的异常类
	//	cout << "BaseException" << endl;
	//	e.printError();
	//}

	//C++标准异常库 Person1

	//Person1 p(10);
	//try {
	//	Person1 p1(150);
	//}
	//catch (out_of_range& e) {
	//	cout << e.what() << endl;
	//}

	//编写自己的异常类 Person1 myOutOfRangeException

	//try {
	//	Person1 p(1000);
	//}
	//catch (exception& e) {
	//	cout << e.what() << endl;
	//}

	//io流概述 
	//标准输入流
	/*
		cin.get()				获取一个字符
		cin.get(一个参数)		读取一个字符
		cin.get(两个参数)		读取字符串
		cin.getline()			获取一行数据
		cin.ignore()			忽略
		cin.peek()				偷窥
		cin.putback()			放回
	*/

	//test9();

    //标准输入流案例

	//test10();

	//标准输出流
	/*
		cout.put();			向缓冲区写字符
		cout.write();		从buffer中写num个字符到当前输出流中
	*/

	//test11();

	//文件流

	test12();

	return 0;
}