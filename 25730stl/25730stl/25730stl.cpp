#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<deque>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<functional>
#include<ctime>
#include<iterator>
#include<numeric>
using namespace std;

void myPrint(int val) {
	cout << val << "\t";
}
class Person {
public:
	Person(string name, int age) {
		this->m_Age = age;
		this->m_Name = name;
	}
	bool operator<(const Person & p) const {
		if (this->m_Age == p.m_Age) {
			return this->m_Name<p.m_Name;
		}
		else return this->m_Age<p.m_Age;
	}
	bool operator==(const Person& p) {
		return this->m_Age == p.m_Age && this->m_Name == p.m_Name;
	}

	string m_Name;
	int m_Age;
};
void myCPrint(Person p) {
	cout << "姓名：" << p.m_Name << "，年龄：" << p.m_Age << endl;
}
void myC1Print(Person* p) {
	cout << "姓名：" << (*p).m_Name << "，年龄：" << (*p).m_Age << endl;
}
//问题出在需要遍历小容器的元素，而for_each遍历提供小容器元素的内容或地址，用小容器本身无法接收
void myVPrint(vector<int> v) {
	for (vector<int>::iterator vit = v.begin(); vit != v.end(); vit++) {
		cout << *vit << "\t";
	}
}
//vector<int>
void test01() {
	vector<int> v; // 创建了一个vector容器，使用泛型int
	//插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//迭代器遍历
	//v.begin()起始迭代器 指向容器中的第一个元素 v.end()结束迭代器 指向容器中最后一个元素的下一个位置
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}
	for_each(itBegin, itEnd, myPrint);
}
//vector<Person> for_each myCPrint
void test02() {
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person>::iterator itBegin = v.begin();
	vector<Person>::iterator itEnd = v.end();
	for_each(itBegin, itEnd, myCPrint);
}
//vector<Person*> for_each myC1Print
void test03() {
	vector<Person*> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	vector<Person*>::iterator itBegin = v.begin();
	vector<Person*>::iterator itEnd = v.end();
	for_each(itBegin, itEnd, myC1Print); // 传入myC1Print时，已经解引用一次（即从itBegin捕获值）
}
//容器的嵌套
void test04() {
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	for (int i = 0; i < 5; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	//遍历
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		//*it vector<int>
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << "\t";
		}
		//for_each((*it).begin(), (*it).end(), myPrint);
		cout << endl;
	}


}
//string的构造、赋值、存取字符  str.assign() str.at(i) 
void test05() {
	//string str1;
	//string str2(str1);
	//string str3 = "abcd";
	//string str4(5, 'a');
	//cout << "str3 = " << str3 << endl;
	//cout << "str4 = " << str4 << endl;

	//string str5;
	//str5.assign("abcdefgh", 5);
	//cout << str5 << endl;
	//string str6;
	//str6.assign(str5, 1, 3);
	//cout << str6 << endl;

	string str = "hello world";
	for (int i = 0; i < str.size(); i++) {
		//cout << str[i] ;
		cout << str.at(i) ; //at会抛出越界异常
	}
	cout << endl;
	try {
		cout << str.at(100) << endl;
	}
	catch (out_of_range e) {
		cout << e.what() << endl;
	}
}
//string的拼接、查找、替换功能  str.append() str.find() str.replace()
void test06() {
	//string str1 = "hello";
	//str1 += " world";
	//cout << str1 << endl;
	//string str2 = "nihao";
	//str1.append(str2);
	//cout << str1 << endl;
	//str1.append(str2, 2, 3);
	//cout << str1 << endl;

	string str3 = "abcdefghide";
	int pos = str3.find("de",4);//参数2 代表起始查找位置，默认为0，未找到返回-1 rfind是从右往左查
	if (pos == -1){
		cout << "未找到子串" << endl;
	}
	else{
		cout << "找到了子串，位置：" << pos << endl;
	}

	str3.replace(1, 3, "1111");//把bcd替换成1111
	cout << str3 << endl;
}
//string的比较、截取子串  str.compare() str.substr()
void test07() {
	string str1 = "abcde";
	string str2 = "Abcdef";
	int ret = str1.compare(str2);
	if (ret == 0) {
		cout << "str1==str2" << endl;
	}
	else if (ret == 1) {
		cout << "str1 > str2" << endl;
	}
	else if (ret == -1) {
		cout << "str1 < str2" << endl;
	}

	string str3 = "abcdefg";
	string subStr = str3.substr(2, 3);
	cout << subStr << endl;
	string email = "wujunxiong02@qq.com";
	//获取@的索引
	int pos = email.find("@"); // pos = 12
	string userName = email.substr(0, pos);
	cout << userName << endl;

	string str4 = "www.nowcoder.com.cn";
	vector<string> v;
	int posdot = -1;
	int start = 0;
	while (true) {
		posdot = str4.find("." , start);
		if (posdot == -1) {
			string subEnd = str4.substr(start, str4.size() - start);
			v.push_back(subEnd);
			break;
		}
		string subStr = str4.substr(start, posdot - start);
		v.push_back(subStr);
		start = posdot + 1;
	}
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}


}
//string的插入、删除、c字符串转换、大小写转换  str.insert() str.erase() str.c_str() toupper/tolower
void test08() {
	string str = "hello";
	str.insert(2, "22");
	cout << str << endl;

	str.erase(2, 2);
	cout << str << endl;

	const char* strc = "hello";
	string str1(strc);
	const char* s = str1.c_str();

	string str2 = "abcABCDE";
	for (int i = 0; i < str2.size(); i++){
		str2[i] = toupper(str2[i]);
	}
	cout << str2 << endl;
}

//vector容器 动态空间 vector<T>::iterator it1 it1的型别为T*
//vector的构造、赋值 v.capacity() v.pushback() v.assign(T*,T*) v.swap(v1)  构造：vector<int> v / v(10,100) / v(T*,T*) 
void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test09() {
	vector<int> v;
	cout << "初始容量" << v.capacity() << endl;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout <<  v.capacity() << endl;
	}
	vector<int> v1(10, 100);
	printVector(v1);
	vector<int> v2(v1.begin(), v1.end());
	vector<int> v3(v1);
	printVector(v2);
	printVector(v3);
	int arr[] = { 2,3,4,1,9 };
	vector<int> v4(arr, arr + sizeof(arr) / sizeof(int));
	vector<int> v5 = v4;
	printVector(v5);
	vector<int> v6;
	v6.assign(v5.begin(), v5.end());
	printVector(v6);

	v6.swap(v3);
	printVector(v6);
	printVector(v3);
}
//vector的大小、数据存取、插入和删除 v.empty() v.size() v.resize() v.at() v.front() v.back() v.insert() v.push_back() v.pop_back() v.erase() v.clear()
void test10() {
	int arr[] = { 2,3,4,1,9 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	if (v.empty()) {
		cout << "v为空" << endl;
	}
	else {
		cout << "v不为空" << endl;
		cout << "size = " << v.size() << endl;
	}
	printVector(v);
	v.resize(3);
	printVector(v);
	v.resize(7);
	printVector(v);
	v.resize(9,100);
	printVector(v);

	cout << v.at(2) << endl;
	cout << "第一个元素：" << v.front() << endl;
	cout << "最后一个元素：" << v.back() << endl;

	v.insert(v.begin(), 100);
	v.insert(v.begin(), 2, 1000);
	printVector(v);
	v.push_back(33);
	printVector(v);
	v.pop_back();
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.clear();
	printVector(v);

}
//vector案例 收缩内存、预留空间、逆序遍历
void test11() {
	//案例1 巧用swap()收缩内存
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.resize(3);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	vector<int>(v).swap(v);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	cout << "=================" << endl;

	//案例2 巧用reserve()预留内存空间
	vector<int> v2;
	v2.reserve(100000);
	int* p = nullptr;
	int num = 0;
	for (int i = 0; i < 100000; i++)//统计添加100000个数据重新开辟空间的次数
	{
		v2.push_back(i);
		if (p!= &v2[0])
		{
			p = &v2[0];
			num++;
		}
	}
	cout << "num = " << num << endl;
	cout << "=================" << endl;

	//案例2 逆序遍历 非质变
	vector<int> v3;
	for (int i = 0; i < 10; i++) {
		v3.push_back(i);
	}
	printVector(v3);
	for (vector<int>::reverse_iterator it = v3.rbegin(); it != v3.rend(); it++) {
		cout << *it << " " ;
	}
	cout << endl;

	//如何判断一个容器的迭代器是否支持随机访问
	vector<int>::iterator itBegin = v.begin();
	itBegin++;

}

//deque容器 双向开口的连续线性空间 迭代器可随机访问
void printDeque(const deque<int>& d) {
	//iterator 普通迭代器
	//reverse_iterator 反转迭代器
	//const_iterator 只读迭代器
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test12() {
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);
	printDeque(d);
	deque<int> d1;
	d1 = d;
	d1.assign(d.begin(), d.end());
	cout << d1.empty() << endl;
	cout << d1.size() << endl;

	d1.push_front(20);
	d1.pop_back();
	d1.push_front(10);
	d1.pop_front();
	d1.insert(d1.begin(), 1000);
	d1.erase(d1.begin());
	printDeque(d1);
}

//stack容器 先进后出 无迭代器
void test13() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	cout << "栈是否为空：" << s.empty() << endl;

	while (!s.empty()) {
		cout << "获取元素的个数：" << s.size() << endl;
		cout << s.top() << endl;
		s.pop();
	}
	cout << "元素的个数：" << s.size() << endl;

}

//queue容器 先进先出 无迭代器
void test14() {
	queue<int> q;
	q.push(1);
	q.push(11);
	q.push(20);
	q.push(15);
	cout << "队列的大小：" << q.size() << endl;
	while (!q.empty()) {
		cout << q.front() << endl;
		cout << q.back() << endl;
		q.pop();
	}
	cout << "队列的大小：" << q.size() << endl;

	queue<Person> q1;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	q1.push(p1);
	q1.push(p2);
	q1.push(p3);
	q1.push(p4);
	while (!q1.empty()) {
		Person pFront = q1.front();
		cout << "姓名：" << pFront.m_Name << "，年龄：" << pFront.m_Age << endl;
		q1.pop();
	}
}

//list容器 双向循环链表 基础功能 迭代器不可随机访问
void printList(const list<int>& li) {
	for (list<int>::const_iterator it = li.begin(); it != li.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test15() {
	list<int> li;
	li.push_back(10);
	li.push_back(20);
	li.push_back(30);
	li.push_back(40);
	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "=============================" << endl;
	for (list<int>::reverse_iterator it = li.rbegin(); it != li.rend(); it++)
	{
		cout << *it << endl;
	}

	list<int> li1(10, 100);
	printList(li1);
	li1.push_back(20);
	li1.push_back(30);
	li1.push_front(40);
	li1.remove(100);
	printList(li1);

	//后删除、插入、删除 类似

}
//list容器的反转、排序
bool myCompare(int v1, int v2) {
	return v1 > v2;
}
bool myComparePerson(Person& p1, Person& p2) {
	//return p1.m_Age < p2.m_Age;
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Name < p2.m_Name;
	}
	return p1.m_Age < p2.m_Age;
}
void test16() {
	list<int> li;
	for (int i = 0; i < 10; i++) {
		li.push_back(i);
	}
	printList(li);
	li.reverse();
	printList(li);
	cout << "==========================" << endl;

	li.push_back(10);
	li.push_back(50);
	li.push_back(30);
	li.push_back(20);
	li.push_back(18);
	li.push_back(22);
	//sort(li.begin(), li.end());//只支持随机访问迭代器的容器
	li.sort(myCompare);// 默认升序 可以加参数变为降序
	printList(li);
	cout << "==========================" << endl;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 30);
	Person p6("fff", 20);
	list<Person> li1;
	li1.push_back(p1);
	li1.push_back(p2);
	li1.push_back(p3);
	li1.push_back(p4);
	li1.push_back(p5);
	li1.push_back(p6);
	//li1.sort(myComparePerson); //利用全局函数myComparePerson
	li1.sort();//利用成员函数，重载<  bool operator<(const Person & p) const
	for (list<Person>::iterator it = li1.begin(); it != li1.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "，年龄：" << (*it).m_Age << endl;
	}
	cout << endl;



}

//set容器 底层是红黑树 所有元素根据元素的键值自动排序 元素既是键值又是实值 键值不可重复、不可随意改变，迭代器其实是一种常值迭代器 不可随机访问
//set容器的查找、统计 对组pair
void printSet(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test17() {
	set<int> s;
	s.insert(10);
	s.insert(40);
	s.insert(40);
	s.insert(30);
	s.insert(12);
	s.insert(5);
	printSet(s);

	set<int>::iterator pos = s.find(300);
	if (pos != s.end()) {
		cout << "找到了元素：" << *pos << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	//对于set来说，count的返回值仅能是0或者1
	int num = s.count(40);
	cout << "40的元素的个数为：" << num << endl;
	set<int>::iterator ret = s.lower_bound(30);//大于等于30的值
	if (ret != s.end()) {
		cout << "找到了lower_bound的值为：" << *ret << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	pair<set<int>::iterator,set<int>::iterator> ret2 = s.equal_range(30);
	if (ret2.first != s.end()) {
		cout << "找到了lower_bound的值为：" << *ret2.first << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	if (ret2.second != s.end()) {
		cout << "找到了upper_bound的值为：" << *ret2.second << endl;
	}
	else {
		cout << "未找到" << endl;
	}

	pair<string, int> p1("Tom", 18);
	cout << "姓名：" << p1.first << endl;
	cout << "年龄：" << p1.second << endl;

	pair<string, int> p2 = make_pair("Tom", 18);
	cout << "姓名：" << p2.first << endl;
	cout << "年龄：" << p2.second << endl;


}
//set容器的排序 与list对比，list是调用sort时添加排序函数作参量，set时构造时增加仿函数作范型
class mySCompare {
public:
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}
};
class mySComparePerson {
public:
	bool operator()(const Person& p1,const Person& p2)const {
		return p1.m_Age>p2.m_Age;
	}
};
void printSet(set<int,mySCompare>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test18() {
	set<int,mySCompare> s;
	s.insert(10);
	s.insert(30);
	s.insert(40);
	s.insert(20);
	s.insert(50);
	printSet(s);
	//sort();//迭代器不支持随机访问

	set<Person,mySComparePerson> ps;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 50);
	Person p4("ddd", 30);
	Person p5("eee", 15);
	ps.insert(p1);
	ps.insert(p2);
	ps.insert(p3);
	ps.insert(p4);
	ps.insert(p5);
	for (set<Person,mySComparePerson>::iterator it = ps.begin(); it != ps.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "，年龄：" << (*it).m_Age << endl;
	}
}

//map容器 底层是红黑树 所有元素根据元素的键值自动排序，元素均是pair，同时拥有实值和键值，first为键值，second为实值，且不允许相同键值
void test19() {
	map<int, int, mySCompare> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;//不建议
	for (map<int, int, mySCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
}

//函数对象 重载函数调用符的类，其对象称之为函数对象，也叫仿函数
//1.仿函数，重载（）的类，使得对象在使用阶段像函数调用，2.且可以拥有自己的一些内部状态，3.函数对象可以作为函数的参数
template<typename T>
class MyPrint:binary_function<int,int,void> {
public:
	void operator()(T test) {
		cout << test << " ";
		m_Count++;
	}
	int m_Count = 0;//内部状态
};
void doWork(MyPrint<string> mp, string str) {
	mp(str);
}
void test20(){
	MyPrint<string> mp;
	mp("hello world");//原本是mp.()("hello world") 不是真正的函数，而是一个对象
	mp("hello world");
	mp("hello world");
	mp("hello world");
	mp("hello world");
	cout << "mp使用的次数：" << mp.m_Count << endl;
	doWork(mp, "hello");
}

//谓词 普通函数或重载operator()返回值是bool类型的函数对象 如果接受一个参数就叫一元谓词，两个参数就是二元谓词
class Greater20 {
public:
	bool operator()(int val) {//一元谓词
		return val > 20;
	}
};
void test21() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	vector<int>::iterator ret = find_if(v.begin(), v.end(), Greater20());
	if (ret != v.end()) {
		cout << "找到了大于20的第一个元素，值为：" << *ret << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	sort(v.begin(), v.end(), mySCompare());
	myVPrint(v);

}


//内建函数对象
void test22() {
	negate<int> n;
	cout << n(10) << endl;
	plus<int> p;
	cout << p(1, 1) << endl;
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myPrint);//此处也可以用仿函数
	cout << endl;
	//sort(v.begin(), v.end(), mySCompare());//此处也可以用普通函数
	sort(v.begin(), v.end(), greater<int>());//此处也可以用普通函数
	printVector(v);

	vector<bool> vb;
	vb.push_back(true);
	vb.push_back(false);
	vb.push_back(true);
	vb.push_back(false);
	vector<bool> vb1;
	vb1.resize(vb.size());
	transform(vb.begin(), vb.end(), vb1.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = vb1.begin(); it != vb1.end(); it++) {
		cout << *it << endl;
	}

}

//函数对象适配器 调整参数 和取反适配器 取反集合
/*
	函数对象适配器
	1.绑定 bind2nd
	2.继承public: binary_function<参数类型，参数类型，返回值类型>
	3.加上const
*/
class MyIPrint :public binary_function<int,int,void>{
public:
	void operator()(int val,int start) const{
		//cout << val + start << " ";
		cout << "val = " << val << ",start = " << start << ",sum = " << val + start << endl;

	}
};
class GreaterFive :public unary_function<int,bool>{
public:
	bool operator()(int val) const {
		return val > 5;
	}
};
void test23() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "请输入起始累加值：" << endl;
	int start = 0;
	//cin >> start;
	for_each(v.begin(), v.end(), bind2nd(MyIPrint(), start));//对于传入的仿函数要求是单参数，出现多参数需要使用适配器,start绑定到第二个参数
	for_each(v.begin(), v.end(), bind1st(MyIPrint(), start));//对于传入的仿函数要求是单参数，出现多参数需要使用适配器，start绑定到第一个参数

	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>::iterator ret = find_if(v1.begin(), v1.end(), GreaterFive());
	if (ret != v1.end()) {
		cout << "找到了大于5的数据：" << *ret << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	vector<int>::iterator ret1 = find_if(v1.begin(), v1.end(), not1(GreaterFive()));//not1 一元取反适配器
	//vector<int>::iterator ret1 = find_if(v1.begin(), v1.end(), not1(bind2nd(greater<int>(), 5)));//not1 一元取反适配器

	if (ret != v1.end()) {
		cout << "找到了小于5的数据：" << *ret1 << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	sort(v.begin(), v.end(), not2(less<int>()));//not2 二元取反适配器
	printVector(v);

}

//函数指针适配器和成员函数适配器
void printVal(int val,int start) {
	cout << val + start << endl;
}
class MemFun {
public:
	MemFun(string name, int age) {
		this->m_Age = age;
		this->m_Name = name;
	}
	void showMem() {
		cout << "姓名：" << this->m_Name << "，年龄：" << this->m_Age << endl;
	}
	string m_Name;
	int m_Age;
};
void test24() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//cout << "请输入起始累加值：" << endl;
	int start = 10;
	//cin >> start;
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(printVal), start));//对于传入参数要求是仿函数，如果使用全局函数，则传入的是函数指针，需要使用指针适配器，使指针转化为函数对象

	vector<MemFun> m;
	MemFun m1("aaa", 10);
	MemFun m2("bbb", 20);
	MemFun m3("ccc", 50);
	m.push_back(m1);
	m.push_back(m2);
	m.push_back(m3);
	for_each(m.begin(), m.end(), mem_fun_ref(&MemFun::showMem));//对于传入参数要求是仿函数，如果使用成员函数，则传入的是函数指针，需要使用成员函数适配器，使指针转化为函数对象
}

//常用的遍历算法 for_each transform
class MyTransform {
public:
	int operator()(int val) {
		return val + 10;
	}
};
void test25() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//for_each(v.begin(), v.end(), myPrint);// 无返回值
	MyPrint<int> mp = for_each(v.begin(), v.end(), MyPrint<int>());// 有返回值，类型是函数对象
	cout << endl;
	cout << "mp中的m_Count的值为：" << mp.m_Count << endl;
	for_each(v.begin(), v.end(), bind2nd(MyIPrint(), 1000));

	vector<int> vt;//目标容器
	//提前分配好内存
	vt.resize(v.size());
	transform(v.begin(), v.end(), vt.begin(), MyTransform());
	for_each(vt.begin(), vt.end(), myPrint);
}

//常用的查找算法 find find_if adjecent_find binary_search count count_if 
class ptrFind:public binary_function<Person*,Person*,bool> {
public:
	bool operator()(Person* p1, Person* p2) const{
		if (p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age) {
			return true;
		}
		else return false;
	}
};
void test26() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator ret = find(v.begin(), v.end(), 5);
	if (ret != v.end()) {
		cout << "找到了元素：" << *ret << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	vector<int>::iterator ret1 = find_if(v.begin(), v.end(), bind2nd(greater<int>(), 5));
	if (ret1 != v.end()) {
		cout << "找到了元素：" << *ret1 << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	vector<Person> vp;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);
	Person p("ddd", 40);
	vector<Person>::iterator ret2 = find(vp.begin(), vp.end(), p);
	if (ret1 != v.end()) {
		cout << "找到了，姓名：" << (*ret2).m_Name << ",找到了，年龄：" << (*ret2).m_Age << endl;
	}
	else {
		cout << "未找到" << endl;
	}

	vector<Person*> vp1;
	Person p11("aaa", 10);
	Person p12("bbb", 20);
	Person p13("ccc", 30);
	Person p14("ddd", 40);
	Person p15("eee", 50);
	vp1.push_back(&p11);
	vp1.push_back(&p12);
	vp1.push_back(&p13);
	vp1.push_back(&p14);
	vp1.push_back(&p15);
	Person* person = new Person("bbb", 20);
	vector<Person*>::iterator ret3 = find_if(vp1.begin(), vp1.end(), bind2nd(ptrFind(), person));
	if (ret3 != vp1.end()) {
		cout << "找到了，姓名：" << (*ret3)->m_Name << ",找到了，年龄：" << (*ret3)->m_Age << endl;
	}
	else {
		cout << "未找到" << endl;
	}
}
void test27() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	vector<int>::iterator ret = adjacent_find(v.begin(), v.end());
	if (ret != v.end()) {
		cout << "找到了相邻的重复元素：" << *ret << endl;
	}
	else {
		cout << "未找到" << endl;
	}

	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	bool ret1 = binary_search(v.begin(), v.end(), 3);//二分查找保证容器内数据有序
	if (ret1) {
		cout << "找到了" << endl;
	}
	else {
		cout << "未找到" << endl;
	}

	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(i);
	}
	v2.push_back(5);
	v2.push_back(5);
	v2.push_back(5);
	v2.push_back(5);
	int num = count(v2.begin(), v2.end(), 5);
	cout << "5元素的个数为：" << num << endl;

	vector<int> v3;
	for (int i = 0; i < 10; i++)
	{
		v3.push_back(i);
	}
	v3.push_back(5);
	v3.push_back(5);
	v3.push_back(5);
	v3.push_back(5);
	int num1 = count_if(v3.begin(), v3.end(), GreaterFive());
	cout << "大于等于5的元素个数为：" << num1 << endl;


}

//常用的排序算法 merge sort random_shuffle reverse
void test28() {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int> vt;
	vt.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());//merge要求v1,v2有序
	//lambda表达式 [](){}匿名函数 无名称无返回值
	for_each(vt.begin(), vt.end(), [](int val) {cout << val << " "; });
	cout << endl;

	vector<int> v3;
	for (int i = 0; i < 10; i++)
	{
		v3.push_back(i);
	}
	sort(v3.begin(), v3.end(),greater<int>());
	for_each(v3.begin(), v3.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//随机数种子
	srand((unsigned int)time(NULL));
	vector<int> v4;
	for (int i = 0; i < 10; i++)
	{
		v4.push_back(i);
	}
	random_shuffle(v4.begin(), v4.end());
	for_each(v4.begin(), v4.end(), [](int val) {cout << val << " "; });
	cout << endl;


	vector<int> v5;
	for (int i = 0; i < 10; i++)
	{
		v5.push_back(i);
	}
	v5.push_back(100);
	v5.push_back(50);
	for_each(v5.begin(), v5.end(), [](int val) {cout << val << " "; });
	cout << endl;
	reverse(v5.begin(), v5.end());
	for_each(v5.begin(), v5.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

//常用的拷贝和替换算法 copy replace replace_if swap
class ReplaceIf {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
void test29() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int> v1;
	v1.resize(v.size());
	copy(v.begin(), v.end(), v1.begin());
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
	cout << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));//遍历输出
	cout << endl;

	replace(v.begin(), v.end(), 3, 300);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	replace_if(v.begin(), v.end(), ReplaceIf(), 2000);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;


	vector<int> v0;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v0.push_back(i);
		v2.push_back(i + 10);
	}
	cout << "交换前数据：" << endl;
	copy(v0.begin(), v0.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	swap(v0, v2);
	cout << "交换后数据：" << endl;
	copy(v0.begin(), v0.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}

//常用的算数生成算法 accumulate fill
void test30() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int sum = accumulate(v.begin(), v.end(), 0);
	cout << sum << endl;

	vector<int> v1;
	v1.resize(10);
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
	cout << endl;
	fill(v1.begin(), v1.end(), 100);
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
}

//常用的集合算法
void test31() {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vt;
	vt.resize(min(v1.size(),v2.size()));
	//交集
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());
	for_each(vt.begin(), itEnd , [](int val) {cout << val << " "; });
	cout << endl;

	//并集
	vector<int> vt1;
	vt1.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd1 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vt1.begin());
	for_each(vt1.begin(), itEnd1, [](int val) {cout << val << " "; });
	cout << endl;

	//差集
	vector<int> vt2;
	vt2.resize(max(v1.size(), v2.size()));
	vector<int>::iterator itEnd2 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vt2.begin());
	for_each(vt2.begin(), itEnd2, [](int val) {cout << val << " "; });
	cout << endl;


}



int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	//test11();
	//test12();
	//test13();
	//test14();
	//test15();
	//test16();
	//test17();
	//test18();
	//test19();
	//test20();
	//test21();
	//test22();
	//test23();
	//test24();
	//test25();
	//test26();
	//test27();
	//test28();
	//test29();
	//test30();
	test31();
}