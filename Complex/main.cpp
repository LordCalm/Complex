#include "Header.h"

int main()
{
	complex a, b(2.0), c(1.0, 1.0);

	cin >> a;
	cout << a << ", " << b << ", abs: " << b.abs() << endl;

	a = b + c.conj();
	a = a * complex(2.0);
	a += c;
	c = a + 2 * b;

	cout << a << ", " << c << endl;

	return 0;
}
