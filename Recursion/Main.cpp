#include <iostream>

int32_t factorial(int32_t N)
{
	if (N == 0)
	{
		return 1;
	}

	return N * factorial(N - 1);

}

int32_t sumDigits(int32_t x)
{
	if (x < 10)
		return x;

	return sumDigits(x / 10) + x % 10;
}

void printBinary(unsigned int n)
{
	if (n > 1) 
	{
		printBinary(n / 2);
	}

	std::cout << n % 2;
}





int main()
{

	std::cout << factorial(6) << '\n';
	std::cout << sumDigits(93427);

	int x{};
	std::cout << "Enter an integer: ";
	std::cin >> x;

	printBinary(static_cast<unsigned int>(x));

}