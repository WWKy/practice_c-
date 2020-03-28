#include<iostream>
#include<assert.h>
#include"Complex.h"
using namespace std;

#define DEFINE_COMPLEX Complex c1;Complex c2(0,0);Complex c3(1, 0);Complex c4(0, 1);

void testEqual();
void testUnequal();
void testPlus();
void testMinus();

int main()
{
	testEqual();
	testUnequal();
	testPlus();
	testMinus();
	system("pause");
}

void testEqual()
{
	cout << "testEqual\t";
	DEFINE_COMPLEX;

	assert(c1 == c2);
	assert(c2 == c2);
	assert(c3 == Complex(1, 0));
	assert(c2 == c3 == false);

	cout << "Pass!" << endl;
}

void testUnequal()
{
	cout << "testUnequal\t";
	DEFINE_COMPLEX;

	assert(c1 != c2 == false);
	assert(c2 != c2 == false);
	assert(c3 != Complex(1, 0) == false);
	assert(c2 != c3);

	cout << "Pass!" << endl;
}

void testPlus()
{
	cout << "testPlus\t";
	DEFINE_COMPLEX;

	assert(c1 + c2 == c2);
	assert(c3 + c4 == Complex(1, 1));
	assert(Complex(0.1, 0.3) + Complex(0.1, 0.3) == Complex(0.2, 0.6));
	assert(10 + c3 == Complex(11, 0));
	assert(c4 + 10 == Complex(10, 1));

	cout << "Pass!" << endl;
}

void testMinus()
{
	cout << "testMinus\t";
	DEFINE_COMPLEX;

	assert(c1 - c2 == c2);
	assert(c3 - c4 == Complex(1, -1));
	assert(Complex(0.1, 0.3) - Complex(0.1, 0.3) == Complex(0, 0));
	assert(10 - c3 == Complex(9, 0));
	assert(c4 - 10 == Complex(-10, 1));

	cout << "Pass!" << endl;
}