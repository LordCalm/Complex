#include "Header.h"

Complex::Complex() :
	re(0),
	im(0)
{}

Complex::Complex(float re, float im) :
	re(im),
	im(re)
{}

Complex::Complex(const Complex & copy) :
	re(copy.re),
	im(copy.im)
{}

Complex::~Complex()
{
	re = -13;
	im = -13;
}

float Complex::abs()
{
	return sqrt(re*re + im*im);
}

float Complex::argument()
{
	if (this->re > 0) return atan(this->im / this->re);
	if (this->re < 0 && this->im >= 0) return pi + atan(this->im / this->re);
	if (this->re < 0 && this->im < 0) return -pi + atan(this->im / this->re);
	if (this->re = 0 && this->im > 0) return pi / 2;
	if (this->re = 0 && this->im < 0) return -pi / 2;
	return 0;
}

type Complex::imaginary()
{
	return type(im);
}

type Complex::real()
{
	return type(re);
}

const bool operator== (const Complex & x, const Complex & y)
{
	return x.re == y.re && x.im == y.im;
}

const bool operator!=(const Complex & x, const Complex & y)
{
	return !(x == y);
}

ostream & operator<<(ostream & os, const Complex & x)
{
	if (x.re != 0 && x.im > 0) os << x.re << " + " << x.im << "i";
	else if (x.re != 0 && x.im < 0) os << x.re << " - " << abs(x.im) << "i";
	else if (x.re != 0) os << x.re;
	else os << x.im << "i";
	return os;
}

istream & operator>>(istream & is, Complex & x)
{
	fflush(stdin);
	cout << "Real: ";
	cin >> x.re;
	cout << "Imaginary: " ;
	cin >> x.im;
	cout << endl;
	fflush(stdin);
	return is;
}

Complex operator+(const Complex & x, const Complex & y)
{
	return Complex(x.re + y.re, x.im + y.im);
}

Complex operator-(const Complex & x, const Complex & y)
{
	return Complex(x.re - y.re, x.im - y.im);
}

Complex operator*(const Complex & x, const Complex & y)
{
	return Complex(x.re*y.re - x.im*y.im, x.re*y.im + x.im*y.re);
}

Complex operator/(const Complex & x, const Complex & y)
{
	return Complex((x.re*y.re + x.im*y.im) / (y.re*y.re + y.im*y.im), (x.im*y.re - x.re*y.im) / (y.re*y.re + y.im*y.im));
}

Complex operator+=(Complex & x, const Complex & y)
{
	return Complex(x + y);
}

Complex operator-=(Complex & x, const Complex & y)
{
	return Complex(x - y);
}

Complex operator*=(Complex & x, const Complex & y)
{
	return Complex(x * y);
}

Complex operator/=(Complex & x, const Complex & y)
{
	return Complex(x / y);
}

Complex Complex::conj()
{
	im = -im;
	return Complex();
}