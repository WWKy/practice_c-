#pragma once
#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0, double imag = 0) :real(real), imag(imag) {};
	bool operator==(const Complex&) const;
	bool operator!=(const Complex&) const;
	double getReal() const { return real; };
	double getImag() const { return imag; };
	void setReal(double a) { real = a; };
	void setImag(double a) { imag = a; }

	friend ostream& operator<<(ostream&, const Complex&);
	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator+(const Complex&, double);
	friend Complex operator+(double, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, double);
	friend Complex operator-(double, const Complex&);

private:
	double real;
	double imag;
};

bool Complex::operator==(const Complex& r) const
{
	return real == r.real && imag == r.imag;
}

bool Complex::operator!=(const Complex& r) const
{
	return real != r.real || imag != r.imag;
}

inline Complex operator+(const Complex &l, const Complex &r)
{
	return Complex(l.real + r.real, l.imag + r.imag);
}

inline Complex operator+(const Complex &l, double r)
{
	return Complex(l.real + r, l.imag);
}

inline Complex operator+(double l, const Complex& r)
{
	return Complex(l + r.real, r.imag);
}

inline Complex operator-(const Complex &l, const Complex &r)
{
	return Complex(l.real - r.real, l.imag - r.imag);
}

inline Complex operator-(const Complex &l, double r)
{
	return Complex(l.real - r, l.imag);
}

inline Complex operator-(double l, const Complex& r)
{
	return Complex(l - r.real, -r.imag);
}

inline ostream& operator<<(ostream& os, const Complex& c)
{
	cout << "(" << c.real << "," << c.imag << ")";
	return os;
}
