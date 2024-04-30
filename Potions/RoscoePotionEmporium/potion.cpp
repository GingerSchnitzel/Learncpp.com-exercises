#include "potion.hpp"

int32_t randomGold()
{
	static std::random_device rd{};                                                 // Random device for seeding the twister
	static std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };      // std::seed_seq resolves underseeding issues 
	static std::mt19937 engine(ss);                                                 // seeding the random engine with the random data
	static std::uniform_int_distribution<int32_t> dist(80, 120);     // generated random integers withing specified range
	int32_t generatedGold = dist(engine);                                              // generates a random integer for row
	// all made static in order not to create objects all over again when function is called
	return generatedGold;
}

std::string getName()
{
	std::cout << "Enter your name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	return name;
}

int32_t charToInt(char c)
{
	return c - '0';
}

