#include "Complex.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	double r, phi;
	cout << "Введите Действительную и Мнимую часть Комплексного числа:\nr = ";
	cin >> r;
	cout << "Phi = ";
	cin >> phi;
	Complex z(r, phi);
	cout << "z = " << z;
	cout << "\nf(z) = z^3+(1+2i)z^2+(1-2i)z^(-5)= (" << (pow(z, 3)) <<
		") + (" << (Complex(1, 2) * pow(z, 2)) << ") + ("
		<< (Complex(1, -2) * pow(z, -5)) << ") = "
		<< Complex((pow(z, 3))) + (Complex(1, 2) * pow(z, 2)) + (Complex(1, -2) * pow(z, -5));
	_getch();
}

int factorial(int x)
{
	if (x == 0) return 1;
	return x * factorial(x - 1);
}
