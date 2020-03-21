#pragma once
#pragma warning(disable : 4996)  
#include <cstring>
#include <iostream>

// strcpy_s���ܿ���0����ô��
class String
{
public:
	String(const char* = nullptr); // ע�⵽��ָ����޲����Ĵ���ʽһ��
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
		data = new char[strlen(c) + 1]; // Ԥ����'\0'
		strcpy(data, c);	// strcpy�Ḵ��'\0'
	}
}

String::String(const String& s)
{
	data = new char[s.length() + 1];
	strcpy(data, s.data);
}

String& String::operator=(const String& s)
{
	if (this == &s)	// ��ֹɵɵ���Ը�ֵ����
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
