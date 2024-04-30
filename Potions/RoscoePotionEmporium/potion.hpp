#ifndef POTION_HPP
#define POTION_HPP

#include <array>
#include <string>
#include <string_view>
#include <iostream>
#include <vector>
#include <random>
#include <cstdint>

namespace Potion
{
	enum Type
	{
		healing,
		mana,
		speed,
		invisibility,
		max_potions
	};
	constexpr std::array <Type, max_potions> types{ healing, mana, speed, invisibility };
	constexpr std::array<int, 4> costs{ 20, 30, 12, 50 };
	const std::array<std::string, max_potions> names{ "healing" , "mana" , "speed" , "invisibility" };

	static void shop()
	{
		std::cout << "Here is our selection for today: \n";
		for (const auto& element : Potion::types)
		{
			std::cout << element + 1 << ")" << Potion::names[element] << " costs " << Potion::costs[element] << '\n';
		}
	}

}
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

class Player
{
private:

	std::string name;
	int32_t gold;
	std::array<int32_t, Potion::max_potions> inventory;

public:
	Player() :
		name{getName()},
		gold{ randomGold() },
		inventory{}
	{

	}
	int32_t getGold() const
	{
		return gold;
	}
	int32_t getInventory(Potion::Type element) const
	{
		return inventory[element];
	}

	void startSession()
	{
		std::cout << "Welcome to Roscoe's potion emporium!\n";
	

	}

};










#endif