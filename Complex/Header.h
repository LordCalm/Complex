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
	complex(float re, float im = 0.0);
	complex(const complex &copy);
	~complex();

	friend const bool operator== (const complex & x, const complex & y);
	friend const bool operator!= (const complex & x, const complex & y);
	friend ostream & operator<< (ostream & os, const complex & x);
	friend istream & operator>> (istream & os, complex & x);
	friend complex operator+ (const complex & x, const complex & y);
	friend complex operator- (const complex & x, const complex & y);
	friend complex operator* (const complex & x, const complex & y);
	friend complex operator/ (const complex & x, const complex & y);
	friend complex operator+= (complex & x, const complex & y);
	friend complex operator-= (complex & x, const complex & y);
	friend complex operator*= (complex & x, const complex & y);
	friend complex operator/= (complex & x, const complex & y);

	float abs();
	float argument();
	type imaginary();
	type real();
	complex conj();

};