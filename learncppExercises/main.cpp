#include "constants.h"
#include <iostream>
#include <cassert>
#include <cmath> 
#include <random>
#include "random.h"
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <cmath>

double getHeight();
void thrownBall(double& inputHeight);
bool isPrime(int32_t x);
int32_t getUserGuess(int32_t min, int32_t max);
void ignoreLine();
bool playAgain();
void playHiLo();
std::vector<std::string> splitInHalf(const std::string& input);
std::vector<std::string> splitInWords(const std::string& inputSentence);
int32_t getIndexOf(const std::string& input, const std::string& substring);
int32_t getIndexOf2(const std::string& input, const std::string& substring);
std::string replaceAll(std::string& input, const std::string& substring, const std::string& replacement);
std::string reverse(std::string& input);
std::vector<std::string> removeDuplicates(const std::vector<std::string>& input);
int32_t countSubstr(const std::string& text, const std::string& substring);
struct Point
{
	float x;
	float y;

	Point(float x, float y)
		:
		x{ x },
		y{ y }
	{
	}
};
float getLength(const Point& A, const Point& B);
float getPerimeter(const Point& A, const Point& B, const Point& C);
void printValidNames(const std::vector<std::string>& names);


int main()
{
	//double towerHeight{ getHeight() };
	//thrownBall(towerHeight);

   /*assert(!isPrime(0));
	assert(!isPrime(1));
	assert(isPrime(2));
	assert(isPrime(3));
	assert(!isPrime(4));
	assert(isPrime(5));
	assert(isPrime(7));
	assert(!isPrime(9));
	assert(isPrime(11));
	assert(isPrime(13));
	assert(!isPrime(15));
	assert(!isPrime(16));
	assert(isPrime(17));
	assert(isPrime(19));
	assert(isPrime(97));
	assert(!isPrime(99));
	assert(isPrime(13417));

	std::cout << "Success!\n";*/


	// Implement a game of hi - lo.
	// First, your program should pick a random integer between 1 and 100. 


	// The user is given 7 tries to guess the number.

	// If the user does not guess the correct number, the program should tell them whether they guessed too high or too low.
	// If the user guesses the right number, the program should tell them they won.If they run out of guesses, 
	// the program should tell them they lost, and what the correct number is.
	// At the end of the game, the user should be asked if they want to play again.
	// If the user doesn’t enter ‘y’ or ‘n’, ask them again.
	//Update your previous solution to handle invalid guesses(e.g.‘x’), out of bounds guesses(e.g. 0 or 101), 
	// or valid guesses that have extraneous characters(e.g. 43x).Also handle the user entering extra characters when 
	// the game asks them whether they want to play again.
	// Hint: Write a separate function to handle the user inputting their guess(along with the associated error handling).

	//std::cout << "Guess #" << 0 << " ";
	//int32_t userGuess = getUserGuess(1, 100);
	//std::cout << userGuess;

	//std::vector<std::string> toSplit = { "test","unudoi","string","sting" };
	//for (auto str : toSplit)
	//{
	//	auto res = splitInHalf(str);
	//	std::cout << res[0] << " " << res[1] << '\n';
	//}

	//std::string paragraph = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur felis leo, laoreet vitae neque a, pretium tempor elit. Sed mollis eget nunc at mollis. Pellentesque egestas gravida nisi quis pulvinar. Donec venenatis risus a leo euismod tristique. In hendrerit risus ac ante commodo, vitae efficitur libero vulputate. Sed cursus neque mauris. Pellentesque sit amet euismod leo. Pellentesque id nisl aliquet, cursus risus in, vestibulum sem. In maximus elit non iaculis sodales. In hac habitasse platea dictumst. Donec egestas turpis sed arcu lobortis, sed volutpat nulla aliquet. Nunc eleifend augue at nibh volutpat sodales. Curabitur aliquam at quam ut pharetra. Integer et suscipit justo. Aenean dignissim augue ut tellus tempus, at sollicitudin leo porta. Integer vel bibendum lectus.";
	//	std::vector<std::string> words = splitInWords(paragraph);
	//for (auto str : words)
	//{
	//	std::cout << str << '\n';
	//}
	std::cout << getIndexOf("Hello, there!", "ello") << '\n';
	std::cout << getIndexOf("Hello, there!", "yes") << '\n';
	std::cout << getIndexOf("Prajitura", "ura") << '\n';
	std::cout << getIndexOf("Prajitura", "nope") << '\n';

	std::cout << getIndexOf2("Hello, there!", "ello") << '\n';
	std::cout << getIndexOf2("Hello, there!", "yes") << '\n';
	std::cout << getIndexOf2("Prajitura", "ura") << '\n';
	std::cout << getIndexOf2("Prajitura", "nope") << '\n';

	std::string toReplace = "This is not a test. I repeat. This is not a test.";
	std::cout << replaceAll(toReplace, "tes", "yestos") << '\n';
	std::string toSwap = "Alexandra";
	std::cout << reverse(toSwap) << '\n';

	std::vector<std::string> input = { "ala","bala","portocala","ala","porto","bala" };
	std::vector<std::string> output = removeDuplicates(input);
	for (auto str : output)
	{
		std::cout << str << '\n';
	}
	std::cout << countSubstr("Despite all my rage I'm still just a rat in a cage", "a");

	Point A(10.f, 20.f); // first param is x, second it's y
	Point B(10.f, 30.f);
	std::cout << getLength(A, B) << '\n';

	std::vector<std::string> names = { "Willy wonka", "Jessie White", "Walter Pink", "tst", "Mannie M.", "H.P. Lovecraft"};
	printValidNames(names);

}


//1. given a string, write a function that splits it in half
std::vector<std::string> splitInHalf(const std::string& input)
{
	std::vector<std::string> stringContainer(2);
	size_t splitInHalfSize = (input.length() / 2);

	for (size_t i{ 0 }; i < input.length(); ++i)
	{
		if (i < splitInHalfSize)
		{
			stringContainer[0].push_back(input[i]);
		}
		else
		{
			stringContainer[1].push_back(input[i]);
		}
	}
	return stringContainer;
}
//2. given a string that contains a paragraph, write a function that splits it into words e.g. for "Mary had a little lamb.", the output should be  ["Marry","had","a","little","lamb"]
std::vector<std::string> splitInWords(const std::string& inputSentence)
{
	std::vector<std::string> stringContainer;
	std::string intermmediateContainer;

	for (size_t i{ 0 }; i < inputSentence.length(); ++i)
	{
		if (inputSentence[i] != ' ' && inputSentence[i] != '.' && inputSentence[i] != ',' && inputSentence[i] != '?' && inputSentence[i] != '!'
			&& inputSentence[i] != '-')
		{
			intermmediateContainer += inputSentence[i];
		}
		else
		{
			if (intermmediateContainer.length() == 0)
			{
				continue;
			}
			else
			{
				stringContainer.push_back(intermmediateContainer);
				intermmediateContainer.clear();
			}
		}
	}

	return stringContainer;
}

//given a string, find the position (index) of a substring inside that string
//return -1 if the string does not contain the substring
int32_t getIndexOf(const std::string& input, const std::string& substring)
{
	size_t counter{ 0 };
	for (size_t i{ 0 }; i < input.length(); ++i)
	{
		if (input[i] == substring[counter])
		{
			++counter;
			if (counter == substring.length())
			{
				return static_cast<int32_t>((i + 1) - counter);
			}
		}
		else
		{
			counter = 0;
		}
	}
	return -1;
}

int32_t getIndexOf2(const std::string& input, const std::string& substring)
{

	for (size_t i{ 0 }; i < input.length(); ++i)
	{
		for (size_t j{ 0 }; j < substring.length(); ++j)
		{
			if (input[i + j] != substring[j])
			{
				break;
			}
			else if (j == substring.length() - 1)
			{
				return static_cast<int32_t>(i);
			}
		}
	}


	return -1;
}
//e.g.: getIndexOf("Hello, there!", "ello") = 1
//      getIndexOf("Hello, there!", "yes") = -1

//given a string, replace all occurences of a substring with the given replacement and return the result as a new string
std::string replaceAll(std::string& input, const std::string& substring, const std::string& replacement)
{
	size_t counter{ 0 };
	for (size_t i{ 0 }; i < input.length(); ++i)
	{
		if (input[i] == substring[counter])
		{
			++counter;
			if (counter == substring.length())
			{
				input.erase((i + 1) - substring.length(), substring.length());
				input.insert((i + 1) - substring.length(), replacement);
			}
		}
		else
		{
			counter = 0;
		}
	}
	return input;
}
//e.g. replaceAll("This is not a test. I repeat. This is not a test.", "test", "yes") = "This is not a yes. I repeat. This is not a yes"

//write a function that returns the reverse of a given string
std::string reverse(std::string& input)
{
	for (size_t i{ 0 }; i <= input.length() / 2; ++i)
	{
		std::swap(input[i], input[input.length() - 1 - i]);
	}
	return input;
}
// reverse("Hello") = "olleH"

//given a vector of strings, remove duplicates from it
std::vector<std::string> removeDuplicates(const std::vector<std::string>& input)
{
	std::vector<std::string> output{};
	for (size_t i{ 0 }; i < input.size(); ++i)
	{
		if (output.size() == 0)
		{
			output.push_back(input[i]);
		}
		else
		{
			for (size_t j{ 0 }; j < output.size(); ++j)
			{
				if (input[i] != output[j])
				{
					if (j == output.size() - 1)
					{
						output.push_back(input[i]);
						break;
					}
					continue;
				}
				break;
			}
		}
	}
	return output;
}
//e.g. ["ala","bala","portocala","ala","porto","bala"] -> ["ala","bala","portocala","porto"]




// write a function that counts the amount of times a substring is contained inside of a text
int32_t countSubstr(const std::string& text, const std::string& substring)
{
	size_t charCounter{ 0 };
	int32_t substringCounter{ 0 };
	for (size_t i{ 0 }; i < text.length(); ++i)
	{
		if (text[i] == substring[charCounter])
		{
			++charCounter;
			if (charCounter == substring.length())
			{
				++substringCounter;
			}
		}
		else
		{
			charCounter = 0;
		}
	}
	return static_cast<int32_t>(substringCounter);

}
//e.g. for the text "Despite all my rage I'm still just a rat in a cage" and substring "a", the count is 6

//model a simple struct that represents a point in 2D space (has an x and y coordinate)


// write a function that takes two such Points and returns the length of the segment determined by them
float getLength(const Point& A, const Point& B)
{
	return static_cast<float>(sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2)));
}

// write a function that calculate the perimeter of a triangle given by 3 points
float getPerimeter(const Point& A, const Point& B, const Point& C)
{

	return getLength(A, B) + getLength(B, C) + getLength(C, A);
}

//e.g.
//Point A(10.f, 20.f); //-> Point needs a constructor that takes two parameters
//Point B(10.f, 30.f);
//getLength(A, B) == 10.0f


// given a vector of strings, print only the valid names separated by a new line
// a valid name must have at least two words starting with a capital letter separated by a space e.g. Markus Markus
// hyphenated names like Anne-Marie are accepted as well as long as there are two such as Anne-Marie Smith
// names that contain initials are also accepte such as H.P. Lovecraft
void printValidNames(const std::vector<std::string>& names)
{
	for (size_t i{ 0 }; i < names.size(); ++i)
	{
		size_t spaceCounter{};
		size_t capitalCounter{};

		if (getIndexOf(names[i], " ") == -1)
		{
			continue;
		}
		if (names[i][0] <= 'A' && names[i][0] >= 'Z')
		{
			continue;
		}
		++capitalCounter;

		for (size_t j{ 0 }; j < names[i].size(); ++j)
		{
			if (names[i][j] == ' ')
			{
				if (names[i][0] == ' ' || names[i][names[i].size() - 1] == ' ')
				{
					continue;
				}
				++spaceCounter;
				if (names[i][j+ 1] >= 'A' && names[i][j + 1] <= 'Z')
				{
					++capitalCounter;
				}
			}
		}
		if (spaceCounter != capitalCounter - 1)
		{
			spaceCounter = 0;
			capitalCounter = 0;
			continue;
		}
		std::cout << names[i] << '\n';
	}
}
// should print:
// Jessie White
// Walter Pink
// Mannie M. 
