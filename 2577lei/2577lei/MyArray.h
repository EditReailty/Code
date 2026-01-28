#pragma once
class MyArray
{
public:
	MyArray();
	MyArray(int capacity); // 带参数的构造函数，指定数组容量
	MyArray(const MyArray& arr); // 拷贝构造函数
	~MyArray(); // 析构函数
	void pushBack(int data);
	int getData(int position);
	void setData(int position, int data);
	int getCapacity() const {
		return m_Capacity; // 获取数组容量
	}
	int getSize() const {
		return m_Size; // 获取数组大小
	}
	int& operator[](int index) { // 重载[]运算符，返回指定位置的元素，引用类型可以作为左值
		return pAddress[index]; // 返回指定位置的元素
	}
private:
	int m_Capacity; // 数组容量
	int m_Size; // 数组大小
	int* pAddress;//底层维护的堆区的数组
};

