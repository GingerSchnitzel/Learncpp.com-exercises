#pragma once
#include <string>
#include <array>
#include <iomanip>
#include <iostream>

namespace Animal 
{
	enum Type;
	struct Data;

}
std::istream& operator>> (std::istream& in, Animal::Type& animal);
void printAnimalData(Animal::Type type);
void getGuess();