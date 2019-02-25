#pragma once
#include <iostream>
#include <math.h>

using namespace std;
typedef float type;

const double pi = 3.1415926535897932384626433832795;

class Complex {
private:
	type re, im;
	int form; // 1 - stand, 2 - trig, 3 -exp
public:
	Complex();
	Complex(float re, float im = 0.0);
	Complex(const Complex &copy);
	~Complex();

	friend const bool operator== (const Complex & x, const Complex & y);
	friend const bool operator!= (const Complex & x, const Complex & y);
	friend ostream & operator<< (ostream & os, const Complex & x);
	friend istream & operator>> (istream & os, Complex & x);
	friend Complex operator+ (const Complex & x, const Complex & y);
	friend Complex operator- (const Complex & x, const Complex & y);
	friend Complex operator* (const Complex & x, const Complex & y);
	friend Complex operator/ (const Complex & x, const Complex & y);
	friend Complex operator+= (Complex & x, const Complex & y);
	friend Complex operator-= (Complex & x, const Complex & y);
	friend Complex operator*= (Complex & x, const Complex & y);
	friend Complex operator/= (Complex & x, const Complex & y);

	float abs() const;
	float argument() const;
	type imaginary() const;
	type real() const;
	Complex conj();

	void Stand();
	void Trig();
	void Exp();
};