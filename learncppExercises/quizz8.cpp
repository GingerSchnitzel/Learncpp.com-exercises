#include "constants.h"
#include <iostream>
#include <cmath> 
#include <random>
#include "random.h"
#include <limits> // for std::numeric_limits
#include <string>



//To start, the user should be asked for the height of the tower in meters
// Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds.
//The ball should not go underneath the ground(height 0).

//Use a function to calculate the height of the ball after x seconds.
//The function can calculate how far the ball has fallen after x seconds using the following formula 
//: distance fallen = gravity_constant * x_seconds2 / 2
double getHeight()
{
	double x{};
	std::cout << "Enter tower height in metres: ";
	std::cin >> x;

	return x;

}


void thrownBall(double& inputHeight)
{
	for (double secondsPassed = 1.0; inputHeight > 0.0; ++secondsPassed)
	{
		double distanceFallen = myConstants::gravity * (secondsPassed * secondsPassed / 2.0);
		inputHeight -= distanceFallen;

		if (inputHeight > 0.0)
		{
			std::cout << "At " << secondsPassed << " seconds, the ball is at height: " << inputHeight << " meters\n";
		}
		else
		{
			std::cout << "At " << secondsPassed << " seconds, the ball is on the ground.\n";
		}
	}
}

bool isPrime(int32_t x)
{
	if (x <= 1)
	{
		return false;
	}
	if (x == 2)
	{
		return true;
	}
	if (x % 2 == 0)
	{
		return false;
	}

	for (int32_t i{ 3 }; i <= std::sqrt(x); i += 2)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // tell std::cin to ignore buffered characters until it finds a newline
	// character (which is removed as well).
}

int32_t getUserGuess(int32_t min, int32_t max)
{
	int32_t x;
	std::string answer;
	size_t pos;

	while (true)
	{
		std::cout << "Input number: ";
		std::getline(std::cin, answer);
		std::cout << "Input:\"" << answer << "\"\n";
		
		try 
		{
			x = std::stoi(answer, &pos); // stoi tries to turn "answer" into an integer
			                             // &pos represents the position where stoi encountered an invalid character 
			if (pos != answer.length())
			{
				continue;
			}
		}
		catch (...) // ... - any exception
		{
			continue;
		}
		if (x < min || x > max)
		{
			//ignoreLine();
			continue;
		}
		//ignoreLine();
		return x; // the return need to be here to break out of the while loop
	}
	
}
bool playAgain()
{
	std::cout << "Would you like to play again?";
	std::string answer;

	while (true)
	{
		std::cout << " Y/N? ";
		
		std::getline(std::cin, answer);
		//std::cout << "Input:\"" << answer << "\"\n";
		if (answer.length() != 1)
		{
			continue;
		}
		
		switch (answer[0])
		{
		case 'Y':
			return true;
		case 'N':
			std::cout << "Thank you for playing! \n";
			return false;
		}
	}
}

void playHiLo()
{
	const int32_t min{ 1 };
	const int32_t max{ 100 };
	std::uniform_int_distribution<int32_t> distribution{ min, max };
	std::mt19937 twister = random::generateRandomNumber();

	do
	{
		int32_t randomNumber = distribution(twister);

		std::cout << "HELLO JOHN! LeT's PlAy a gAmE. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is. \n";

		const int32_t maxAttempts{ 7 };

		for (int32_t attempts{ 1 }; attempts <= maxAttempts; ++attempts)
		{
			std::cout << "Guess #" << attempts << " ";
			int32_t userGuess = getUserGuess(min, max);

			if (userGuess == randomNumber)
			{
				std::cout << "Correct!You win!\n";
				break;
			}
			else if (userGuess > randomNumber)
			{
				std::cout << "Your guess is too high.\n";
				if (attempts == maxAttempts)
				{
					std::cout << "Sorry, you lose.The correct number was: " << randomNumber << '\n';
				}
			}
			else
			{
				std::cout << "Your guess is too low.\n";
				if (attempts == maxAttempts)
				{
					std::cout << "Sorry, you lose.The correct number was: " << randomNumber << '\n';
				}
			}

		}

	} while (playAgain());

}

