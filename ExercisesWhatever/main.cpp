#include <iostream>
#include <string>

double getDouble();
char getOperator();
void arithmeticDoubles(double x, double y, char c);
int getInt();
bool contains(int32_t container[], size_t container_size, int32_t contents[], size_t contents_size);

int main()
{
	//double x{ getDouble()};
	//double y{ getDouble()};
	//char operation{ getOperator()};
	//arithmeticDoubles(x, y, operation);

	//double towerHeight{ getDouble() };
	//constexpr double gravity = 9.8;
	//for (int i = 0; towerHeight > 0; ++i)
	//{
	//	double j = towerHeight - (gravity * i * i) / 2;

	//	if (j < 0)
	//	{
	//		std::cout << " At " << i << " seconds " << "the ball is on ground \n";
	//		break;
	//	}
	//	else
	//	{
	//		std::cout << " At " << i << " seconds " << " the ball is at " << j << " meters " << '\n';
	//	}

	//}

	/*
	std::cout << "Enter a single char: ";

	char character{};

	std::cin >> character;
	int charTOint{ character };

	std::cout << "You entered " << "'" << character << "'" << " which has the value of " << "'" << // static_cast<int>(character) charTOint
	charTOint << "'" << " in the ASCII table." << '\n';
	*/

	//int x{ getInt() };
	//if (!(x % 2)) // x % 2 == 0
	//{
	//	std::cout << "The number is even. \n";
	//}
	//else
	//{                           
	//	std::cout << "The number is odd. \n";
	//}
	int32_t container[] = { 10, 20, 30 };
	size_t container_size = 3;
	int32_t contents[] = { 10, 20, 30 };
	size_t contents_size = 3;
	contains(container, container_size, contents, contents_size);

}



double getDouble()
{
	double x{};
	std::cout << "Enter height: ";
	std::cin >> x;
	return x;
}

int getInt()
{
	int x{};
	std::cout << "Enter an integer: ";
	std::cin >> x;
	return x;
}



char getOperator()
{
	char c{};
	std::cout << "Enter one of the following: +, -, *, or /: ";
	std::cin >> c;
	return c;
}

void arithmeticDoubles(double x, double y, char c)
{
	if (c == '+')
		std::cout << x << " + " << y << " = " << x + y;
	else if (c == '-')
		std::cout << x << " - " << y << " = " << x - y;
	else if (c == '*')
		std::cout << x << " * " << y << " = " << x * y;
	else if (c == '/')
		std::cout << x << " / " << y << " = " << x / y;
}
bool contains(int32_t container[], size_t container_size, int32_t contents[], size_t contents_size)
{

	if (contents_size > container_size)
	{
		return false;
	}
	
	//if hasElement[n] is true, then we have elmenent of index n from contents inside container 
	bool hasElement[100]{ 0 };

	// given an array of integers named containers and an array of integers named contents and their sizes
	// return true if all the elements of contents are contained inside of container

	for (size_t i = 0; i < container_size; ++i)
	{
		for (size_t j = 0; j < contents_size; ++j)
		{
			if (container[i] == contents[j])
				hasElement[j] = true;
			break;
		}
	}
	for (size_t i = 0; i < contents_size; ++i)
	{
		if (!hasElement)
		{
			return false;
		}
	}
	return true;
	
}
