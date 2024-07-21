#include <iostream>
#include <numeric> 
#include <vector>


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

bool operator<= (const Fraction& f1, const Fraction& f2)
{
	return !(operator>(f1, f2));
}

bool operator>= (const Fraction& f1, const Fraction& f2)
{
	return !(operator<(f1, f2));
}


struct StudentGrade
{
	std::string name{};
	char grade{};
};


class GradeMap
{
private:
	std::vector<StudentGrade> m_map{};

public:
	char& operator[] (const std::string& name)
	{
		auto found{ std::find_if(m_map.begin(), m_map.end(),
					[name](const auto& student) { // this is a lambda that captures name from the surrounding scope
						return (student.name == name); // so we can use name here
					}) };

		if (found != m_map.end())
		{
			return found->grade;
		}

		// otherwise create a new StudentGrade for this student and add
		// it to the end of our vector.
		m_map.emplace_back(std::string{ name }); // C++20
		//	m_map.push_back(StudentGrade{std::string{name}}); // push_back version

			// and return the element
		return m_map.back().grade;
	}
};



int main()
{
	/*
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	*/
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}