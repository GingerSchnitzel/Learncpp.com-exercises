#include <vector>
#include <iostream>


int32_t vectrSum(std::vector<int32_t>& vectr);
void sumSort(std::vector<std::vector<int32_t>>& vectr);



int main()
{
	// Sort a vector of vectors of int32_t based on the sum of all the elements
	// For {20,30} , {100,-40} , {1,3}, the sorted result is {1,3}, {20,30}, {100,-40}
	std::vector<std::vector<int32_t>> vectrr{ {20,30} , {100,-40} , {1,3} };
	sumSort(vectrr);

}

// 1. A function that returns the sum of the elements of a vector of int32_t
int32_t vectrSum(std::vector<int32_t> & vectr)
{
	int32_t sum{};
	for (size_t i{ 0 }; i < vectr.size(); ++i)
	{
		sum += vectr[i];
	}
	return sum;
}

void sumSort(std::vector<std::vector<int32_t>>& vectr)
{
	std::vector<int32_t> swap;
	for (size_t i{ 0 }; i < vectr.size() - 1; ++i)
	{
		for (size_t j{ 1 }; j < vectr.size(); ++j)
		{
			if (vectrSum(vectr[i]) > vectrSum(vectr[j]))
			{
				swap = vectr[i];
				vectr[i] = vectr[j];
				vectr[j] = swap;
			}
		}
	}
}