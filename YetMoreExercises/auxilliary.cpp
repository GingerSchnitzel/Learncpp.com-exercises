#include "auxilliary.h"
#include <iostream>
#include <stdint.h>


int get_small_integer()
{
	int x{};
	std::cout << "Enter a small integer: ";
	std::cin >> x;

	return x;
}

int get_larger_integer()
{
	int x{};
	std::cout << "Enter a large integer: ";
	std::cin >> x;

	return x;
}