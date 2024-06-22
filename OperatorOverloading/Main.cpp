#include <iostream>
#include <numeric> 


class Fraction
{
private:
	int32_t m_numerator;
	int32_t m_denominator;

public:
	explicit Fraction(int32_t numerator, int32_t denominator = 1) :
		m_numerator{ numerator },
		m_denominator{ denominator }

	{
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd) // Make sure we don't try to divide by 0
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}
	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
	friend std::istream& operator>>(std::istream& in, Fraction& f1);

	friend bool operator== (const Fraction& f1, const Fraction& f2);
	friend bool operator!= (const Fraction& f1, const Fraction& f2);

	friend bool operator< (const Fraction& f1, const Fraction& f2);
	friend bool operator> (const Fraction& f1, const Fraction& f2);

	friend bool operator<= (const Fraction& f1, const Fraction& f2);
	friend bool operator>= (const Fraction& f1, const Fraction& f2);

};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction{ f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction{ f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1)
{
	return Fraction{ f1 * value };
}

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& f1)
{
	int numerator{};
	char ignore{};
	int denominator{};

	// Overwrite the values of f1
	in >> numerator >> ignore >> denominator;

	if (in)
		f1 = Fraction{ numerator, denominator };

	return in;
}

bool operator== (const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator == f2.m_numerator) && (f2.m_denominator == f2.m_denominator);
}
//Overloaded operator< and operator> for the Fraction class
bool operator!= (const Fraction& f1, const Fraction& f2)
{
	return !(operator==(f1, f2));
}

bool operator< (const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator * f2.m_denominator < f2.m_numerator * f1.m_denominator);
}

bool operator> (const Fraction& f1, const Fraction& f2)
{
	return operator<(f2, f1);
}

int main()
{
	Fraction f1{ 2, 5 };
	f1.print();

	Fraction f2{ 3, 8 };
	f2.print();

	Fraction f3{ f1 * f2 };
	f3.print();

	Fraction f4{ f1 * 2 };
	f4.print();

	Fraction f5{ 2 * f2 };
	f5.print();

	Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
	f6.print();

	Fraction f7{ 0, 6 };
	f7.print();

	return 0;
}