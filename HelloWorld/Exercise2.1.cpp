#include <iostream>
int get_value_from_user();




int main()
{
	std::cout << "Enter an integer: ";
	std::cout << get_value_from_user();
	std::cout << get_value_from_user() << " doubled is: " << get_value_from_user() * 2 << '\n';
}

int get_value_from_user()
{
	int value{};
	std::cin >> value;
	return value; 
}