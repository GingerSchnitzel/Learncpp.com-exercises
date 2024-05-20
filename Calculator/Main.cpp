#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int32_t getInteger();
char getOperation();
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
ArithmeticFunction getArithmeticFunction(char op);



int main()
{
	int32_t x{ getInteger() };
	char operation{ getOperation() };
	int32_t y{ getInteger() };

	ArithmeticFunction fcn{ getArithmeticFunction(operation) };

	if (fcn)
	{
		std::cout << x << ' ' << operation << ' ' << y << " = " << fcn(x, y) << '\n';

	}

}


int32_t getInteger()
{
	while (true)
	{


		std::cout << "Enter an integer: ";
		int x{};
		std::cin >> x;


		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "That wasn't a valid input. Try again.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;

		}
		return x;
	}

}

char getOperation()
{
	char op{};

	do
	{
		std::cout << "Enter an operation ('+', '-', '*', '/'): ";
		std::cin >> op;
	} while (op != '+' && op != '-' && op != '*' && op != '/');

	return op;
}

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

ArithmeticFunction getArithmeticFunction(char op)
{
	switch (op)
	{
	case '+': return &add;
	case '-': return &subtract;
	case '*': return &multiply;
	case '/': return &divide;
	}

	return nullptr;
}