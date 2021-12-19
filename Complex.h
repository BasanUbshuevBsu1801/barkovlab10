#pragma once
#include "iostream"
#include "conio.h"

using namespace std;

class Complex
{
	double r, phi;
public:
	double getReal() const;
	double getImaginary() const;
	void setR(double r);
	void setPhi(double phi);
	Complex(double r, double phi);
	friend ostream& operator << (ostream& stream, const Complex& z);
	friend Complex operator -(Complex a, Complex b);
	friend Complex operator +(Complex a, Complex b);
	friend Complex operator /(Complex a, Complex b);
	friend Complex operator *(Complex a, Complex b);
	friend Complex pow(const Complex& z, int stepen);
	friend Complex tanh(const Complex& z);
};

int factorial(int x);
