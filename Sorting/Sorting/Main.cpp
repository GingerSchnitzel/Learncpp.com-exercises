#include <iostream>
#include <utility>


int main()
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