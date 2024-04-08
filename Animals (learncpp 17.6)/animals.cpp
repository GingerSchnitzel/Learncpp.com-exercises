#include <string>
#include <array>
#include <iomanip>
#include <iostream>
#include "animals.h"

namespace Animal
{
	enum Type
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals,
	};

	struct Data
	{
		std::string name{};
		int32_t legs{};
		std::string sound{};
	};
	std::array <Type, max_animals> types{ chicken, dog, cat, elephant, duck, snake };
	std::array <Data, max_animals> data
	{
		Data{ "chicken",    2, "cluck" },
		Data{ "dog",        4, "woof" },
		Data{ "cat",        4, "meow" },
		Data{ "elephant",   4, "pawoo" },
		Data{ "duck",       2, "quack" },
		Data{ "snake",      0, "hissss" },
	};

}

std::istream& operator>> (std::istream& in, Animal::Type& animal)
{
	std::string input{};
	in >> std::ws;
	std::getline(in, input);

	for (size_t i{ 0 }; i < Animal::data.size(); ++i)
	{
		if (input == Animal::data[i].name)
		{
			animal = static_cast<Animal::Type>(i);
			return in;
		}
	}
	in.setstate(std::ios_base::failbit);
	return in;
}

void printAnimalData(Animal::Type type)
{
	const Animal::Data& animal{ Animal::data[type] };
	std::cout << "A " << animal.name << " has " << animal.legs << " legs and says " << animal.sound << ".\n";
}

void getGuess()
{


	while (true)
	{
		std::cout << "Enter an animal: ";
		Animal::Type type{};
		std::cin >> type;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "That animal couldn't be found.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		printAnimalData(type);
		return;
	}
}