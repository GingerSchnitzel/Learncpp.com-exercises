#ifndef RANDOM_H
#define RANDOM_H

#include <random>

namespace random
{ 
	inline std::mt19937 generateRandomNumber()
	{
		std::random_device rd{};
		std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // seed sequence type;  it will generate as many additional unbiased seed values as 
		                                                                    // needed to initialize a PRNG’s state.
		return std::mt19937{ ss }; 
	}
}
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



#endif