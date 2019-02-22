#include "Header.h"

complex::complex() :
	re(0),
	im(0)
{}

complex::complex(float re, float im) :
	re(im),
	im(re)
{}

complex::complex(const complex & copy) :
	re(copy.re),
	im(copy.im)
{}

complex::~complex()
{
	re = -13;
	im = -13;
}

float complex::abs()
{
	return sqrt(re*re + im*im);
}

float complex::argument()
{
	if (this->re > 0) return atan(this->im / this->re);
	if (this->re < 0 && this->im >= 0) return pi + atan(this->im / this->re);
	if (this->re < 0 && this->im < 0) return -pi + atan(this->im / this->re);
	if (this->re = 0 && this->im > 0) return pi / 2;
	if (this->re = 0 && this->im < 0) return -pi / 2;
}

type complex::imaginary()
{
	return type(im);
}

type complex::real()
{
	return type(re);
}

const bool operator== (const complex & x, const complex & y)
{
	return x.re == y.re && x.im == y.im;
}

const bool operator!=(const complex & x, const complex & y)
{
	return !(x == y);
}

ostream & operator<<(ostream & os, const complex & x)
{
	if (x.re != 0 && x.im > 0) os << x.re << " + " << x.im << "i";
	else if (x.re != 0 && x.im < 0) os << x.re << " - " << abs(x.im) << "i";
	else if (x.re != 0) os << x.re;
	else os << x.im << "i";
	return os;
}

istream & operator>>(istream & is, complex & x)
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

complex operator+(const complex & x, const complex & y)
{
	return complex(x.re + y.re, x.im + y.im);
}

complex operator-(const complex & x, const complex & y)
{
	return complex(x.re - y.re, x.im - y.im);
}

complex operator*(const complex & x, const complex & y)
{
	return complex(x.re*y.re - x.im*y.im, x.re*y.im + x.im*y.re);
}

complex operator/(const complex & x, const complex & y)
{
	return complex((x.re*y.re + x.im*y.im) / (y.re*y.re + y.im*y.im), (x.im*y.re - x.re*y.im) / (y.re*y.re + y.im*y.im));
}

complex operator+=(complex & x, const complex & y)
{
	return complex(x + y);
}

complex operator-=(complex & x, const complex & y)
{
	return complex(x - y);
}

complex operator*=(complex & x, const complex & y)
{
	return complex(x * y);
}

complex operator/=(complex & x, const complex & y)
{
	return complex(x / y);
}

complex complex::conj()
{
	im = -im;
	return complex();
}