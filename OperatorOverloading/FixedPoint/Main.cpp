#include <iostream>
#include <cstdint>
#include <cassert>

namespace Constants
{
	constexpr int8_t overflow{ 99 };
}

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
		// If either (or both) of the non-fractional and fractional part of the number are negative, 
		// the number should be treated as negative
		if (m_nonFractional < 0 || m_fractional < 0) 

		{
			// We must make sure both parts of the number are negative no matter which one is declared 
			// negative, so that when converting the whole number into a double, the result is correct
			// (negative number + negative number, not positive + negative)
			if (m_nonFractional > 0) 
			{
				m_nonFractional = -m_nonFractional;
			}
			if (m_fractional > 0)
			{
				m_fractional = -m_fractional;
			}

		}
		// Treat overflow in each direction 
		m_nonFractional += m_fractional / 100;
		m_fractional = m_fractional % 100;
	}

	explicit operator double() const
	{
		return m_nonFractional + (static_cast<double>(m_fractional) / 100);
	}

	friend bool testDecimal(const FixedPoint2& fp)
	{
		if (fp.m_nonFractional >= 0)
			return fp.m_fractional >= 0 && fp.m_fractional < 100;
		else
			return fp.m_fractional <= 0 && fp.m_fractional > -100;
	}

};

std::ostream& operator<< (std::ostream& out, const FixedPoint2& number)
{
	out << static_cast<double> (number);
	return out;
}

int main()
{
	FixedPoint2 a{ 1, 104 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 2.04);
	assert(testDecimal(a));

	FixedPoint2 b{ 1, -104 };
	assert(static_cast<double>(b) == -2.04);
	assert(testDecimal(b));

	FixedPoint2 c{ -1, 104 };
	assert(static_cast<double>(c) == -2.04);
	assert(testDecimal(c));

	FixedPoint2 d{ -1, -104 };
	assert(static_cast<double>(d) == -2.04);
	assert(testDecimal(d));

	return 0;
}