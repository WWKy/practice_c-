#pragma once
#pragma warning(disable : 4996)  
#include <cstring>
#include <iostream>

// strcpy_s不能拷贝0吗？怎么用
class String
{
public:
	String(const char* = nullptr); // 注意到空指针和无参数的处理方式一样
	String(const String&);
	String& operator=(const String&);
	~String();
	void print() const;
	int length() const { return strlen(data); };
private:
	char* data;
};

inline String::String(const char* c)
{
	if (c == nullptr)
	{
		data = new char[1];
		data[0] = '\0';
	}
	else
	{
		data = new char[strlen(c) + 1]; // 预留给'\0'
		strcpy(data, c);	// strcpy会复制'\0'
	}
}

String::String(const String& s)
{
	data = new char[s.length() + 1];
	strcpy(data, s.data);
}

String& String::operator=(const String& s)
{
	if (this == &s)	// 防止傻傻的自赋值操作
		return *this;

	delete[] data;
	data = new char[s.length() + 1];
	strcpy(data, s.data);
	return *this;
}

String::~String()
{
	delete[] data;
}

void String::print() const
{
	std::cout << data << std::endl;
}
