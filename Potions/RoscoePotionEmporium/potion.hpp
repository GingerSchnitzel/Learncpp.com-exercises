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
	constexpr std::array<int32_t, 4> costs{ 20, 30, 12, 50 };
	const std::array<std::string, max_potions> names{ "healing" , "mana" , "speed" , "invisibility" };



}

int32_t randomGold();
std::string getName();
int32_t charToInt(char c);



class Player
{
private:

	std::string name;
	int32_t gold;
	std::array<int32_t, Potion::max_potions> inventory;

public:
	Player() :
		name{ getName() },
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

	bool buy(Potion::Type type)
	{
		if (gold < Potion::costs[type])
		{
			return false;
		}

		gold -= Potion::costs[type];
		++inventory[type];
		return true;
	}

	Potion::Type whichPotion()
	{

		std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
		char input{};
		while (true)
		{
			std::cin >> input;
			if (!std::cin)
			{
				std::cin.clear(); // put us back in 'normal' operation mode
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}


			if (!std::cin.eof() && std::cin.peek() != '\n')
			{
				std::cout << "I didn't understand what you said.  Try again: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			if (input == 'q')
			{
				return Potion::max_potions;
			}


			int32_t val{ charToInt(input) };
			if (val >= 0 && val < Potion::max_potions)
			{
				return static_cast<Potion::Type>(val);
			}

			// It wasn't a valid potion selection
			std::cout << "I didn't understand what you said.  Try again: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}



	}

	void shop()
	{
		while (gold > Potion::costs[2])
		{
			std::cout << "Here is our shop's selection for today: \n";
			for (const auto& element : Potion::types)
			{
				std::cout << element << ") " << Potion::names[element] << " costs: " << Potion::costs[element] << '\n';
			}
		
			Potion::Type which{ whichPotion() };
			if (which == Potion::max_potions)
				return;

			bool success{ buy(which) };
			if (!success)
				std::cout << "You can not afford that.\n\n";
			else
				std::cout << "You purchased a potion of " << Potion::names[which] << ".  You have " << getGold() << " gold left.\n\n";
		}
	}

	void printInventory()
	{
		std::cout << "Your inventory contains: \n";

		for (const auto& element : Potion::types)
		{
			if (getInventory(element) > 0)
				std::cout << getInventory(element) << "x potion of " << Potion::names[element] << '\n';
		}

		std::cout << "You escaped with " << getGold() << " gold remaining.\n";
	}

	void startSession()
	{

		std::cout << "Hello, " << name << ", you have " << getGold() << " gold.\n\n";
		shop();
		std::cout << '\n';
		printInventory();
		std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

	}


};










#endif