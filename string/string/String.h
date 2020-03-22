#pragma once
#pragma warning(disable : 4996)  
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class String;
ostream& operator<<(ostream&, const String&);

class String
{
public:
	String(const char* = nullptr);	// 注意到空指针和无参数的处理方式一样
	String(const String&);
	String& operator=(const char*);
	String& operator=(const String&);
	~String() { delete[] data; };
	bool operator==(const char*) const;
	bool operator!=(const char*) const;
	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	String operator+(const char*) const;
	String operator+(const String&) const;
	String& operator+=(const char*);
	String& operator+=(const String&);
	String operator*(int) const;
	String& operator*=(int);
	int length() const { return strlen(data); };
	char* getData() const { return data; };
private:
	static char* plusCore(const char*, const char*);
	static char* mutipleCore(const char*, int);
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
		strcpy(data, c);				// strcpy会复制'\0'
	}
}

inline String::String(const String& s)
{
	data = new char[s.length() + 1];
	strcpy(data, s.data);
}

inline String& String::operator=(const char* c)
{
	delete[] data;
	data = new char[strlen(c) + 1];
	strcpy(data, c);
	return *this;
}

inline String& String::operator=(const String& s)
{
	if (this == &s)				// 防止傻傻的自赋值操作
		return *this;
	return operator=(s.data);
}

inline bool String::operator==(const char* r) const
{
	return strcmp(data, r) == 0 ? true : false;
}

inline bool String::operator!=(const char* r) const
{
	return strcmp(data, r) != 0 ? true : false;
}

inline bool String::operator==(const String& r) const
{
	return operator==(r.data);
}

inline bool String::operator!=(const String & r) const
{
	return operator!=(r.data);
}

inline String String::operator+(const char* c) const
{
	return String(plusCore(data, c));
}

inline String String::operator+(const String& r) const
{
	return operator+(r.data);
}

inline String & String::operator+=(const char* r)
{
	char* new_c = plusCore(data, r);
	delete[] data;
	data = new_c;
	return *this;
}

inline String& String::operator+=(const String& r)
{
	return operator+=(r.data);
}

inline String String::operator*(int n) const
{
	return String(mutipleCore(data, n));
}

inline String& String::operator*=(int n)
{
	char* new_c = mutipleCore(data, n);
	delete[] data;
	data = new_c;
	return *this;
}

inline char* String::plusCore(const char* left, const char *right)
{
	char* new_c = new char[strlen(left) + strlen(right) + 1];
	strcpy(new_c, left);
	strcpy(new_c + strlen(left), right);
	return new_c;
}

inline char* String::mutipleCore(const char* c, int n)
{
	char *new_c;
	if (n == 0)
	{
		new_c = new char[1];
		new_c[0] = '\0';
	}
	else if (n == 1)
	{
		new_c = new char[strlen(c)+1];
		strcpy(new_c, c);
	}
	else
	{
		int len = strlen(c);
		new_c = new char[len*n + 1];
		for (int i = 0; i < n; i++) 
		{
			strcpy(new_c+i*len, c);
		}
	}
	return new_c;
}

inline ostream& operator<<(ostream& os, const String& s)
{
	cout << s.getData();
	return os;
}