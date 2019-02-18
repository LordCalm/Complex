#include "Header.h"

int main()
{
	complex z1(2, 5);
	complex z2(3, -2);
	if (z2 == 1) cout << "Yes!" << endl;
	cout << z1 / z2 << endl;
	cout << z1 * 2 << endl;
	return 0;
}