#include "Header.h"

int main()
{
	Complex a, b(2), c(1.0, 1.0);

	cin >> a;
	a.Exp();
	b.Trig();
	cout << a << ", " << b << ", abs: " << b.abs() << endl;

	a = b + c.conj();
	a = a * Complex(2.0);
	a += c;
	c = a + 2 * b;

	cout << a + b << ", " << c << endl;

	return 0;
}
