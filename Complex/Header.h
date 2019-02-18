#pragma once
#include <iostream>
#include <math.h>

using namespace std;
typedef float type;

const double pi = 3.1415926535897932384626433832795;

class complex {
private:
	type re, im;
public:
	complex();
	complex(const int x);
	complex(const float x);
	complex(const int im, const int re);
	complex(const float im, const float re);

	friend const bool operator== (const complex & x, const complex & y);
	friend const bool operator!= (const complex & x, const complex & y);
	friend ostream & operator<< (ostream & os, const complex & x);
	friend complex operator+ (const complex & x, const complex & y);
	friend complex operator- (const complex & x, const complex & y);
	friend complex operator* (const complex & x, const complex & y);
	friend complex operator/ (const complex & x, const complex & y);

	float module();
	float argument();
	type imaginary();
	type real();

};