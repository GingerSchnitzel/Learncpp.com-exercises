#include <iostream>
#include "Exercises.h"


// loop_for_numbers_on_row(10);

/*
int height{5};

for (int i{ 1 }; i <= height; ++i)
{
	loop_for_spaces(height - i);
	loop_for_numbers_on_row(i);
	std::cout << '\n';
}
std::cout << '\n';
*/

// 1 2 3 . . 1 2 3
// 1 2 . . . . 1 2
// 1 . . . . . . 1




// LOOP 1 (SIMPLE PYRAMID)
/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/

void loop_1(int height)
{
	for (int i{ 1 }; i <= height; ++i)
	{
		for (int j{ 1 }; j <= i; ++j)
		{
			std::cout << j << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

// LOOP 2 (RIGHT PYRAMID)
/*
# # # # 1
# # # 1 2
# # 1 2 3
# 1 2 3 4
1 2 3 4 5
*/

void loop_2(int height)
{
	for (int i{ 1 }; i <= height; ++i)
	{
		for (int x{ 1 }; x <= height - i; ++x)
		{
			std::cout << ". ";
		}
		for (int j{ 1 }; j <= i; ++j)
		{
			std::cout << j << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

// LOOP 3 (BOTH PYRAMIDS FROM ABOVE)

/*
# # 1 # # 1 # #
# 1 2 # # 1 2 #
1 2 3 # # 1 2 3
 */

void loop_3(int height)
{
	for (int i{ 1 }; i <= height; ++i)
	{
		for (int x{ 1 }; x <= height - i; ++x)
		{
			std::cout << ". ";
		}
		for (int j{ 1 }; j <= i; ++j)
		{
			std::cout << j << " ";
		}
		std::cout << ". . ";

		for (int y{ 1 }; y <= i; ++y)
		{
			std::cout << y << " ";
		}
		for (int z{ 1 }; z <= height - i; ++z)
		{
			std::cout << ". ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void loop_for_spaces(int height)
{
	for (int x{ 1 }; x <= height; ++x)
	{
		std::cout << ". ";
	}
}

void loop_for_numbers_on_row(int numbers)
{
	for (int j{ 1 }; j <= numbers; ++j)
	{
		std::cout << j << " ";
	}
}



// LOOP 4 (YEAH, THIS THING)

// 1 . . . . . . 1
// 1 2 . . . . 1 2
// 1 2 3 . . 1 2 3


void loop4(int height)
{
	for (int i{ 1 }; i <= height; ++i)
	{
		loop_for_numbers_on_row(i);
		loop_for_spaces(height - i + 1);
		//loop_for_spaces(2); The thing is, it's either this or (height - i + 1)
		loop_for_spaces(height - i + 1);
		loop_for_numbers_on_row(i);
		std::cout << '\n';
	}
}

// LOOP 5 (THE THING ABOVE AND ITS BROTHER)

// 1 . . . . . . 1
// 1 2 . . . . 1 2
// 1 2 3 . . 1 2 3

// 1 2 3 . . 1 2 3
// 1 2 . . . . 1 2
// 1 . . . . . . 1

void loop5(int height)
{
	loop4(height);

	for (int i{ 1 }; i <= height; ++i)
	{
		/*
		for (int j{1}; j <= height - i + 1; ++j)
		{
			std::cout << j << " ";
		}
		for (int x{ 1 }; x <= i; ++x)
		{
			std::cout << ". ";
		}
		for (int y{ 1 }; y <= i; ++y)
		{
			std::cout << ". ";
		}
		for (int z{ 1 }; z <= height - i + 1; ++z)
		{
			std::cout << z << " ";
		}
		*/
		loop_for_numbers_on_row(height - i + 1);
		loop_for_spaces(i);
		loop_for_spaces(i);
		loop_for_numbers_on_row(height - i + 1);
		std::cout << '\n';
	}
	std::cout << '\n';
}

// LOOP 5 COPY (THE THING ABOVE FOR EXERCISING)

// 1 . . . . . . 1
// 1 2 . . . . 1 2
// 1 2 3 . . 1 2 3

// 1 2 3 . . 1 2 3
// 1 2 . . . . 1 2
// 1 . . . . . . 1

void loop5_copy(int height)
{
	loop4(height);

	for (int i{ 1 }; i <= height; ++i)
	{
		for (int j{ 1 }; j <= height - i + 1; ++j)
		{
			std::cout << j << " ";
		}
		for (int x{ 1 }; x <= i; ++x)
		{
			std::cout << ". ";
		}
		for (int z{ 1 }; z <= i; ++z)
		{
			std::cout << ". ";
		}
		for (int y{ 1 }; y <= height - i + 1; ++y)
		{
			std::cout << y << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

// LOOP 6 [JUST FOR THE SAKE OF IT :)]     1 (i) j=1  1

// 1 2 3 4.1 2 3 4  i = 1
// 1 2 3 . . 1 2 3  i = 2
// 1 2 . . . . 1 2
// 1 . . . . . . 1

void loop6(int height)
{
	for (int row{ 1 }; row <= height; ++row)
	{
		for (int numbers_on_row_left{ 1 }; numbers_on_row_left <= height - row + 1; ++numbers_on_row_left)
		{
			if (numbers_on_row_left == height)
			{
				//std::cout << numbers_on_row_left;
				std::cout << " ";
				std::cout << ".";
			}
			else if (numbers_on_row_left < height)
			{
				// std::cout << numbers_on_row_left << " ";
				std::cout << "  ";
			}

		}
		for (int spaces1{ 1 }; spaces1 <= row - 1; ++spaces1)
		{
			// std::cout << "x";
			std::cout << ". ";
		}
		for (int spaces2{ 1 }; spaces2 <= row - 1; ++spaces2)
		{
			//std::cout << "x";
			std::cout << spaces2;
		}
		/*for (int numbers_on_row_right{1}; numbers_on_row_right <= height - row + 1; ++numbers_on_row_right)
		{
				//std::cout << numbers_on_row_right;
				std::cout << " ";
		}
		*/
		std::cout << '\n';
	}
}

// LOOP 7 (PYRAMID MARGIN)

/*       *
	   *   *
	 *       *
   *           *
 * * * * * * * * *   */

void loop7(int height)
{
	for (int i{ 1 }; i <= height; ++i)
	{
		for (int j{ 1 }; j <= height - i + 1; ++j)
		{
			if (j == height)
			{
				std::cout << " ";
				std::cout << ".";
			}
			else if (j < height)
			{
				std::cout << "  ";
			}
		}
		for (int x{ 1 }; x <= i - 1; ++x)
		{
			if (x == 1 || i == height)
				std::cout << "." << " ";
			else
			{
				std::cout << " " << " ";
			}
		}

		for (int y{ 2 }; y <= height; ++y)
		{
			if (y == i || i == height)
			{
				std::cout << ". ";
			}
			else
			{
				std::cout << "  ";
			}
		}

		std::cout << '\n';

	}
}
// LOOP 8 

/*
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
*/

void loop8(int height)
{
	for (int i{ 1 }; i <= height; ++i)
	{
		for (int j{ 1 }; j <= i; ++j)
		{

			std::cout << i << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

// LOOP 9

/*
5 5 5 5 5
4 4 4 4
3 3 3
2 2
1
*/

void loop9(int height)
{
	for (int i{ height }; i >= 1; --i)
	{
		for (int j{ 1 }; j <= i; ++j)
		{

			std::cout << i << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}


// LOOP 9
/*
5
4 4
3 3 3
2 2 2 2
1 1 1 1 1

*/

void loop10(int height)
{
	for (int i{ height }; i >= 1; --i)
	{
		std::cout << i << " ";

		for (int j{ 1 }; j < height - i + 1; ++j)
		{
			std::cout << i << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

/// LOOP 11

/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/

void loop11(int height)
{
	int x{ 1 }; // by initializing "x" outside the loop, we make sure that x will actually
	//increase with each iteration and will not reset at the beginning of each row
	for (int i{ 1 }; i <= height; ++i)
	{
		for (int j{ 1 }; j <= i; ++j)
		{
			std::cout << x << " ";
			x++;
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

// LOOP 12

/*  * * * * *   |       1 2 3 4 5   .....1 2 3 4 5
   * * * * *    |      1 2 3 4 5    ....1 2 3 4 5
  * * * * *     |     1 2 3 4 5     ...1 2 3 4 5
 * * * * *      |    1 2 3 4 5      ..1 2 3 4 5
* * * * *       |   1 2 3 4 5       .1 2 3 4 5

*/

void loop12(int height)
{
	for (int i{ 1 }; i <= height; ++i)
	{
		for (int j{ 1 }; j <= height - i; ++j)
		{
			std::cout << " ";
		}
		for (int x{ 1 }; x <= height; ++x)
		{
			std::cout << x << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

int test()
{
	std::cout << "Hello!";

	return 5;

}

int veryTalkativeFunction()
{
	std::cout << "Hello! My name is " << __FUNCTION__ << " and I'm going to return a number. The number is equal to 5! I think.\n";
	return 5;
}

int getValueFromUser()
{
	std::cout << "Introduce an integer: ";
	int input{};
	std::cin >> input;
	std::cout << ".";

	return input;
}


void printDoubleValueFromUser(int num)
{
	std::cout << "Number introduced: " << num << ". " << "Number * 2 = " << num * 2 << ". \n";
}
// printDoubleValueFromUser(getValueFromUser());

// Write a function named sumTo() that takes an integer parameter named value, and returns the sum of all the numbers from 1 to value.
// For example, sumTo(5) should return 15, which is 1 + 2 + 3 + 4 + 5

int32_t sumTo(int32_t value)
{
	int32_t sum{ 0 };
	for (int32_t i{ 1 }; i <= value; ++i)
	{
		sum += i;

	}
	return sum;

}

// Starting at 1, and counting upward, replace any number divisible only by three with the word “fizz”, any number only divisible
//  by five with the word “buzz”, and any number divisible by both 3 and 5 with the word “fizzbuzz”. 
// Implement this game inside a function named fizzbuzz() that takes an parameter determining what number to count up to. 
// Use a for-loop and a single if-else chain (meaning you can use as many else-if as you like).
// Modify the FizzBuzz program you wrote in the previous quiz to add the rule that numbers divisible by seven should be replaced with “pop”. 
// In this version, using an if/else chain will result in a function that is too long. 
// Optimize your function so that it uses only one if-statement per divisor.

void fizzBuzzPop(int32_t number)
{
	for (int32_t i{ 1 }; i <= number; ++i)
	{
		bool printed{ false };
		if (i % 3 == 0)
		{
			std::cout << "Fizz";
			printed = true;
		}
		if (i % 5 == 0)
		{
			std::cout << "Buzz";
			printed = true;
		}
		if (i % 7 == 0)
		{
			std::cout << "Pop";
			printed = true;
		}
		if (!printed)
		{
			std::cout << i;
		}
		std::cout << '\n';
	}
}
