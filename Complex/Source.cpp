#include "Header.h"

Complex::Complex() :
	re(0),
	im(0),
	form(1)
{}

Complex::Complex(float re, float im) :
	re(im),
	im(re),
	form(1)
{}

Complex::Complex(const Complex & copy) :
	re(copy.re),
	im(copy.im),
	form(1)
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

ostream & operator<<(ostream & os, Complex & x)
{
	if (x.form == 1)
	{
		if (x.re != 0 && x.im > 0) os << x.re << " + " << x.im << "i";
		else if (x.re != 0 && x.im < 0) os << x.re << " - " << abs(x.im) << "i";
		else if (x.re != 0) os << x.re;
		else os << x.im << "i";
		return os;
	}
	else if (x.form == 2)
	{
		float arg = x.argument();
		if (x.re != 0 && x.im > 0) os << x.abs() << " * (Cos("  << arg / pi << "*pi) + i*Sin(" << arg / pi << "*pi))";
		else if (x.re != 0 && x.im < 0) os << x.abs() << " * (Cos(" << abs(arg / pi) << "*pi) - i*Sin(" << abs(arg / pi) << "*pi))";
		else if (x.re != 0) os << x.abs() << " * Cos(" << arg / pi << "*pi)";
		else os << x.abs() << "*i*Sin(" << arg / pi << "*pi)";
		return os;
	}
	else
	{
		float arg = x.argument();
		if(arg > 0) os << x.abs() << "exp(i*" << arg / pi << "*pi)";
		else if (arg == 0) os << x.abs();
		else if(arg < 0) os << x.abs() << "exp(-i*" << abs(arg / pi) << "*pi)";
		return os;
	}
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

void Complex::Stand()
{
	form = 1;
}

void Complex::Trig()
{
	form = 2;
}

void Complex::Exp()
{
	form = 3;
}
