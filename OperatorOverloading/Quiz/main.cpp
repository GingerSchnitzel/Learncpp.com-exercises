#include <iostream>
#include <cstdint>

class Average
{
private:
	int32_t sum;
	int32_t numbersCount;


public:
	Average()
		:sum{}
		,numbersCount{}
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Average& average)
	{
		out << static_cast<double>(average.sum) / average.numbersCount;

		return out;
	}

	Average& operator+= (int32_t num)
	{
		sum += num;
		++numbersCount;


		return *this;
	}
};

int main()
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n';

	avg += 8;
	std::cout << avg << '\n';

	avg += 24;
	std::cout << avg << '\n';

	avg += -10;
	std::cout << avg << '\n';

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n';

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}