#include "Header.h"

complex::complex() :
	re(0),
	im(0)
{}

complex::complex(const int x) :
	re(x),
	im(0)
{}

complex::complex(const float x) :
	re(x),
	im(0)
{}

complex::complex(const int im, const int re) :
	re(im),
	im(re)
{}

complex::complex(const float im, const float re) :
	re(im),
	im(re)
{}

float complex::module()
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
	if (x.re != 0 && x.im != 0) os << x.re << " + " << x.im << "i";
	else if (x.re != 0) os << x.re;
	else os << x.im << "i";
	return os;
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
