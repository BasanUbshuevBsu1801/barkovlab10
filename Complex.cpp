#include "Complex.h"

double Complex::getReal() const
{
	return this->r;
}

double Complex::getImaginary() const
{
	return this->phi;
}

void Complex::setR(double r)
{
	this->r = r;
}

void Complex::setPhi(double phi)
{
	this->phi = phi;
}

Complex::Complex(double r, double phi)
	:r(r), phi(phi) { }

ostream& operator << (ostream& stream, const Complex& z)
{
	if (z.getImaginary() >= 0)
	{
		stream << z.getReal() << "+" << z.getImaginary() << "*i";
	}
	else
	{
		stream << z.getReal() << z.getImaginary() << "*i";
	}
	return stream;
}

Complex operator*(Complex a, Complex b)
{
	return Complex(a.getReal() * b.getReal(), a.getImaginary() * b.getImaginary());
}

Complex operator -(Complex a, Complex b)
{
	return Complex(a.getReal() - b.getReal(), a.getImaginary() - b.getImaginary());
}

Complex operator /(Complex a, Complex b)
{
	return Complex(((a.getReal() * b.getReal()) - (a.getImaginary() * b.getImaginary() * (-1))) / (pow(b.getReal(), 2) + pow(b.getImaginary(), 2)), ((a.getReal() * b.getImaginary() * (-1)) + (a.getImaginary() * b.getReal())) / (pow(b.getReal(), 2) + pow(b.getImaginary(), 2)));
}

Complex operator +(Complex a, Complex b)
{
	return Complex(a.getReal() + b.getReal(), a.getImaginary() + b.getImaginary());
}

Complex pow(const Complex& z, int stepen) {
	Complex result(0, 0);
	for (int i = 0; i <= stepen; i++)
	{
		switch (i % 4)
		{
		case 1:
			result.setPhi((factorial(stepen) / (factorial(i) * factorial(stepen - i))) * pow(z.getReal(), stepen - i) * pow(z.getImaginary(), i));
			break;
		case 2:
			result.setR((factorial(stepen) / (factorial(i) * factorial(stepen - i))) * pow(z.getReal(), stepen - i) * pow(z.getImaginary(), i));
			break;
		case 3:
			result.setPhi((factorial(stepen) / (factorial(i) * factorial(stepen - i))) * pow(z.getReal(), stepen - i) * pow(z.getImaginary(), i));
			break;
		case 0:
			result.setR((factorial(stepen) / (factorial(i) * factorial(stepen - i))) * pow(z.getReal(), stepen - i) * pow(z.getImaginary(), i));
			break;
		}
	}

	return result;
}
Complex tanh(const Complex& z)
{
	return Complex(sinh(2 * z.getReal()), sin(2 * z.getImaginary())) / Complex(cosh(2 * z.getReal()) + cos(2 * z.getImaginary()), 0);
}
