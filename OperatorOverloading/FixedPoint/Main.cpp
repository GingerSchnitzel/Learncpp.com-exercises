#include <iostream>
#include <cstdint>
#include <cassert>

class FixedPoint2
{
private:
	int16_t m_nonFractional;
	int8_t m_fractional;

public:
	FixedPoint2(int16_t nonFractional, int8_t fractional)
		: m_nonFractional{ nonFractional }
		, m_fractional{ fractional }

	{
		if (m_nonFractional < 0 || m_fractional < 0) // If either (or both) of the non-fractional and fractional part of the number are negative, the number should be treated as negative
		
		{
			if (m_nonFractional > 0) // We must make sure both parts of the number are negative no matter which one is declared negative, so that when converting the whole number into a double, the result is correct
				                     // (negative number + negative number, not positive + negative)
			{
				m_nonFractional = -m_nonFractional;
			}
			if (m_fractional > 0) 
			{
				m_fractional = -m_fractional;
			}

		}
	}

	explicit operator double() const
	{
		return m_nonFractional + (static_cast<double>(m_fractional) / 100);
	}

};

std::ostream& operator<< (std::ostream& out, const FixedPoint2& number)
{
	out << static_cast<double> (number);
	return out;
}

int main()
{
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 34.56);

	FixedPoint2 b{ -2, 8 };
	assert(static_cast<double>(b) == -2.08);

	FixedPoint2 c{ 2, -8 };
	assert(static_cast<double>(c) == -2.08);

	FixedPoint2 d{ -2, -8 };
	assert(static_cast<double>(d) == -2.08);

	FixedPoint2 e{ 0, -5 };
	assert(static_cast<double>(e) == -0.05);

	FixedPoint2 f{ 0, 10 };
	assert(static_cast<double>(f) == 0.1);

	return 0;
}