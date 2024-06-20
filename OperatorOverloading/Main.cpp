#include <iostream>


class Fraction
{
private:
	int32_t m_numerator;
	int32_t m_denominator;

public:
	explicit Fraction(int32_t numerator, int32_t denominator = 1):
		m_numerator{ numerator },
		m_denominator{ denominator }

	{

	}

	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};


int main()
{
	Fraction f1{ 1, 4 };
	f1.print();

	Fraction f2{ 1, 2 };
	f2.print();

	return 0;
}