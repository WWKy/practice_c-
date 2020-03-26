#include<iostream>
#include<cstring>
#include<assert.h>
using namespace std;

inline bool isBig(char c) 
{
	return c >= 'A' && c <= 'Z' ? true : false;
}

inline bool isSmall(char c)
{
	return c >= 'a' && c <= 'z' ? true : false;
}

inline char cToBig(char c) 
{
	if (isSmall(c))
		c += 'A' - 'a';
	return c;
}

inline char cToSmall(char c)
{
	if (isBig(c))
		c -= 'A' - 'a';
	return c;
}

void strToBig(char* str) 
{
	if (!str)
		return;

	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		str[i] = cToBig(str[i]);
	}
}

void strToSmall(char* str)
{
	if (!str)
		return;

	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		str[i] = cToSmall(str[i]);
	}
}

int main() 
{
	char *str_1 = nullptr;
	strToBig(str_1);
	assert(str_1== nullptr);

	char str_2[] = "";
	strToBig(str_2);
	assert(strcmp(str_2 ,"")==0);

	char str_3[] = "a";
	strToBig(str_3);
	assert(strcmp(str_3, "A") == 0);

	char str_4[] = "A";
	strToBig(str_4);
	assert(strcmp(str_4, "A") == 0);

	char str_5[] = "abc";
	strToBig(str_5);
	assert(strcmp(str_5, "ABC") == 0);

	char str_6[] = "xyz";
	strToBig(str_6);
	assert(strcmp(str_6, "XYZ") == 0);

	char str_7[] = "XYZ";
	strToBig(str_7);
	assert(strcmp(str_7, "XYZ") == 0);

	char str_8[] = "AbC";
	strToBig(str_8);
	assert(strcmp(str_8, "ABC") == 0);

	char str_9[] = "abcd:123EFG";
	strToBig(str_9);
	assert(strcmp(str_9, "ABCD:123EFG") == 0);

	cout << "All test Pass!" << endl;

	system("pause");

}