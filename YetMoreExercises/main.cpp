#include <iostream>
#include "auxilliary.h"
#include <stdint.h>
#include <utility>
#include <ios>       // for std::boolalpha
#include <iostream>

template <typename T>
class Pair
{
private:
	T first{};
	T second{};

public:
	// When we define a member function inside the class definition,
	// the template parameter declaration belonging to the class applies
	Pair(const T& first, const T& second)
		: first{ first }
		, second{ second }
	{
	}

	bool isEqual(const Pair<T>& pair);
};

// When we define a member function outside the class definition,
// we need to resupply a template parameter declaration
template <typename T>
bool Pair<T>::isEqual(const Pair<T>& pair)
{
	return this->first == pair.first && this->second == pair.second;
}


int main()
{
	/*int smaller{get_small_integer()};
	int larger{ get_larger_integer() };
	int copy_smaller = { smaller };
	int copy_larger = { larger };


	if (smaller > larger)
	{
		int actually_smaller{};
		actually_smaller = larger;
		larger = smaller;
	
		
		std::cout << "The larger integer is " << smaller << '\n';
		std::cout << "The smaller integer is " << actually_smaller << '\n';
	}
	else
	{
		std::cout << "The larger integer is " << larger << '\n';
		std::cout << "The smaller integer is " << smaller << '\n';
	}
	std::cout << "The initial larger integer was " << copy_larger << '\n';
	std::cout << "Larger now is " << larger << '\n';
	std::cout << "The initial smaller integer was " << copy_smaller << '\n';
	std::cout << "Smaller now is " << smaller << '\n';

	//std::cout << "But your input for smaller was " << smaller << "and your input for larger was " << larger;
	*/
	int a = 5;
	int b = a++;
	std::cout << b; 
	int c = 7;
	std::cout << c++;


	Pair p1{ 5, 6 }; // uses CTAD to infer type Pair<int>
	std::cout << std::boolalpha << "isEqual(5, 6): " << p1.isEqual(Pair{ 5, 6 }) << '\n';
	std::cout << std::boolalpha << "isEqual(5, 7): " << p1.isEqual(Pair{ 5, 7 }) << '\n';

}
