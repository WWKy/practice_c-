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
	static char* copyString(const char*);
	static char* copyEmptyString();
	static char* plusCore(const char*, const char*);
	static char* mutipleCore(const char*, int);

	char* data;
};

inline String::String(const char* c_str)
{
	data = c_str ? copyString(c_str) : copyEmptyString();
}

inline String::String(const String& str)
{
	data = copyString(str.data);
}

inline String& String::operator=(const char* right)
{
	delete[] data;
	data = copyString(right);
	return *this;
}

inline String& String::operator=(const String& right)
{
	if (this == &right)				// 防止傻傻的自赋值操作
		return *this;
	return operator=(right.data);
}

inline bool String::operator==(const char* right) const
{
	return strcmp(data, right) == 0 ? true : false;
}

inline bool String::operator!=(const char* right) const
{
	return strcmp(data, right) != 0 ? true : false;
}

inline bool String::operator==(const String& right) const
{
	return operator==(right.data);
}

inline bool String::operator!=(const String & right) const
{
	return operator!=(right.data);
}

inline String String::operator+(const char* right) const
{
	return String(plusCore(data, right));
}

inline String String::operator+(const String& right) const
{
	return operator+(right.data);
}

inline String & String::operator+=(const char* right)
{
	char* new_c = plusCore(data, right);
	delete[] data;
	data = new_c;
	return *this;
}

inline String& String::operator+=(const String& right)
{
	return operator+=(right.data);
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

inline char* String::copyString(const char *c_str)
{
	char* new_c = new char[strlen(c_str) + 1];	// +1预留给'\0'
	strcpy(new_c, c_str);						// strcpy会复制'\0'
	return new_c;
}

inline char* String::copyEmptyString()
{
	char* new_c = new char[1];
	new_c[0] = '\0';
	return new_c;
}

inline char* String::plusCore(const char* left, const char *right)
{
	char* new_c = new char[strlen(left) + strlen(right) + 1];
	strcpy(new_c, left);
	strcpy(new_c + strlen(left), right);
	return new_c;
}

inline char* String::mutipleCore(const char* c_str, int n)
{
	char *new_c;
	if (n == 0)
	{
		new_c = copyEmptyString();
	}
	else if (n == 1)
	{
		new_c = copyString(c_str);
	}
	else
	{
		int len = strlen(c_str);
		new_c = new char[len*n + 1];
		for (int i = 0; i < n; i++)
		{
			strcpy(new_c + i*len, c_str);
		}
	}
	return new_c;
}

inline ostream& operator<<(ostream& os, const String& s)
{
	cout << s.getData();
	return os;
}