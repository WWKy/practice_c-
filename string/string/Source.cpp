#include"String.h"
#include<iostream>

void testConstructor();
void testCopyConstructor();
void testAssigment();

int main() 
{
	//testConstructor();
	//testCopyConstructor();
	testAssigment();

	system("pause");
}


void testConstructor() 
{
	std::cout << "¹¹Ôìº¯Êý²âÊÔ**********" << std::endl;
	String s1(nullptr);
	String s2("");
	String s3("a");
	String s4("abcdefg");
	s1.print();
	s2.print();
	s3.print();
	s4.print();
	std::cout << s1.length() << std::endl;
	std::cout << s2.length() << std::endl;
	std::cout << s3.length() << std::endl;
	std::cout << s4.length() << std::endl;
	std::cout << std::endl;

}

void testCopyConstructor() 
{
	std::cout << "¿½±´¹¹Ôìº¯Êý²âÊÔ**********" << std::endl;
	String s1(nullptr);
	String s2("");
	String s3("a");
	String s4("abcdefg");

	String s5(s1);
	String s6(s2);
	String s7(s3);
	String s8(s4);
	s5.print();
	s6.print();
	s7.print();
	s8.print();
	std::cout << s5.length() << std::endl;
	std::cout << s6.length() << std::endl;
	std::cout << s7.length() << std::endl;
	std::cout << s8.length() << std::endl;
	std::cout << std::endl;
}


void testAssigment()
{
	std::cout << "¿½±´¸³Öµº¯Êý²âÊÔ**********" << std::endl;
	String s1(nullptr);
	String s2("");
	String s3("a");
	String s4("abcdefg");
	String s5;
	
	s5 = s1;
	s5.print();
	std::cout << s5.length() << std::endl;

	s5 = s2;
	s5.print();
	std::cout << s5.length() << std::endl;

	s5 = s3;
	s5.print();
	std::cout << s5.length() << std::endl;

	s5 = s4;
	s5.print();
	std::cout << s5.length() << std::endl;

	s5 = s5;
	s5.print();
	std::cout << s5.length() << std::endl;

	std::cout << std::endl;

}