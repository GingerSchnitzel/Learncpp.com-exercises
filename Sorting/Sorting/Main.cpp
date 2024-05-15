#include <iostream>
#include <utility>
#include <string>
#include <algorithm>


size_t getNameCount();
void getNames(std::string* names, std::size_t length);
void printNames(std::string* names, std::size_t length);

int main()
{
	//SELECTION SORT => LARGEST -> SMALLEST
	{
		int32_t array[]{ 30, 50, 20, 10, 40 };
		constexpr size_t length{ std::size(array) };


		for (size_t i{ 0 }; i < length - 1; ++i)
		{
			size_t biggestIndex = i;
			for (size_t j{ i + 1 }; j < length; ++j)
			{
				if (array[j] > array[biggestIndex])
				{
					biggestIndex = j;
				}
			}
			std::swap(array[i], array[biggestIndex]);

		}

		for (const auto& element : array)
		{
			std::cout << element << ' ';
		}
		std::cout << '\n';
	}

	//BUBBLE SORT => SMALLEST -> LARGEST
	{
		int32_t array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
		constexpr size_t length{ std::size(array) };

		for (size_t i{ 0 }; i < length - 1; ++i)
		{
			bool swapped = { false };
			for (size_t j{ 0 }; j < length - i - 1; ++j)
			{
				if (array[j] > array[j + 1])
				{
					std::swap(array[j], array[j + 1]);
					swapped = true;
				}
			}
			if (!swapped)
			{
				std::cout << "Early termination on iteration: " << i + 1 << '\n';
				break;
			}
		}

		for (const auto& element : array)
		{
			std::cout << element << ' ';
		}
		std::cout << '\n';
	}

	size_t length{ getNameCount() };
	auto* names{ new std::string[length]{} };
	getNames(names, length);
	std::sort(names, names + length);
	printNames(names, length);
	delete[] names;
}

size_t getNameCount()
{
	std::cout << "How many names would you like to enter? ";
	std::size_t length{};
	std::cin >> length;

	return length;
}

void getNames(std::string* names, std::size_t length)
{
	for (std::size_t i{ 0 }; i < length; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::getline(std::cin >> std::ws, names[i]);
	}
}

void printNames(std::string* names, std::size_t length)
{
	std::cout << "\nHere is your sorted list:\n";

	for (std::size_t i{ 0 }; i < length; ++i)
	{
		std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
	}
}