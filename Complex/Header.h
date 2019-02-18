#pragma once
#include <iostream>

using namespace std;
typedef float type;

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
};