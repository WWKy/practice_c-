#include<iostream>
#include<assert.h>
#include"String.h"

using std::cout;
using std::endl;

void testConstructor();
void testEqual();
void testCopyConstructor();
void testAssigment();
void testPlus();
void testSelfPlus();
void testMultiple();
void testSelfMultiple();

#define DEFINE_STRINGS String s1(nullptr);String s2("");String s3;String s4("a");String s5("hello");

int main()
{
	testConstructor();
	testEqual();
	testCopyConstructor();
	testAssigment();
	testPlus();
	testSelfPlus();
	testMultiple();
	testSelfMultiple();

	system("pause");
}

void testConstructor()
{
	cout << "testConstructor\t\t";
	DEFINE_STRINGS;

	assert(strcmp(s1.getData(), "") == 0);
	assert(strcmp(s2.getData(), "") == 0);
	assert(strcmp(s3.getData(), "") == 0);
	assert(strcmp(s4.getData(), "a") == 0);
	assert(strcmp(s5.getData(), "hello") == 0);
	assert(strcmp(s5.getData(), "Hello") != 0);

	cout << "Pass!" << endl;
}

void testEqual()
{
	cout << "testEqual\t\t";
	DEFINE_STRINGS;

	assert(s1 == s1);
	assert(s2 == s2);
	assert(s3 == s3);
	assert(s1 == s2);
	assert(s2 == s3);

	assert(s4 == s4);
	assert(s5 == s5);

	assert(s5 == s1 == false);
	assert(s5 == s4 == false);

	cout << "Pass!" << endl;
}


void testCopyConstructor()
{
	cout << "testCopyConstructor\t";
	DEFINE_STRINGS;

	String s_1(s1);
	String s_2(s2);
	String s_3(s3);
	String s_4(s4);
	String s_5(s5);

	assert(s_1 == s1);
	assert(s_2 == s2);
	assert(s_3 == s3);
	assert(s_4 == s4);
	assert(s_5 == s5);
	assert(s_1 != s_5);

	cout << "Pass!" << endl;
}

void testAssigment()
{
	cout << "testAssigment\t\t";
	DEFINE_STRINGS;

	s1 = s5;
	s2 = s5;
	s3 = s5;
	s4 = s4;
	s5 = s5;

	assert(s1 == s5);
	assert(s2 == s5);
	assert(s3 == s5);
	assert(s4 != s5);
	assert(s5 == s5);

	cout << "Pass!" << endl;
}

void testPlus()
{
	cout << "testPlus\t\t";
	DEFINE_STRINGS;

	assert(s1 + s2 == String(""));
	assert(s1 + s4 == String("a"));
	assert((s4 + s4) == String("aa"));
	assert((s5 + s5) == String("hellohello"));
	assert(String(" ") + String(" ") == String("  "));
	assert(String(" ") + String(" ") != String(" "));

	assert(s1 + s2 == (""));
	assert(s1 + s4 == ("a"));
	assert((s4 + s4) == ("aa"));
	assert((s5 + s5) == ("hellohello"));
	assert(String(" ") + String(" ") == ("  "));
	assert(String(" ") + String(" ") != (" "));

	cout << "Pass!" << endl;
}

void testSelfPlus()
{
	cout << "testSelfPlus\t\t";
	DEFINE_STRINGS;

	s1 += s1;
	s2 += s2;
	s3 += s3;
	s4 += s4;
	s5 += "abc";

	assert(s1 == "");
	assert(s2 == "");
	assert(s3 == "");
	assert(s4 == "aa");
	assert(s5 == "helloabc");

	cout << "Pass!" << endl;
}

void testMultiple()
{
	cout << "testMultiple\t\t";
	DEFINE_STRINGS;

	assert(s1 * 0 == "");
	assert(s1 * 1 == s1);
	assert(s1 * 2 == s1);
	assert(s4 * 0 == "");
	assert(s4 * 1 == "a");
	assert(s4 * 2 == "aa");
	assert(s5 * 0 == "");
	assert(s5 * 1 == "hello");
	assert(s5 * 2 == "hellohello");
	assert(s5 * 3 == "hellohellohello");
	assert(String(" ") * 2 == "  ");

	cout << "Pass!" << endl;
}

void testSelfMultiple()
{
	cout << "testSelfMultiple\t";
	DEFINE_STRINGS;

	s1 *= 0;
	assert(s1 == "");
	s1 *= 1;
	assert(s1 == "");
	s1 *= 2;
	assert(s1 == "");

	s4 *= 1;
	assert(s4 == "a");
	s4 *= 2;
	assert(s4 == "aa");
	s4 *= 0;
	assert(s4 == "");

	s5 *= 1;
	assert(s5 == "hello");
	s5 *= 2;
	assert(s5 == "hellohello");
	s5 *= 0;
	assert(s5 == "");

	cout << "Pass!" << endl;
}