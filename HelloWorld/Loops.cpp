#include <iostream>
#include "Exercises.h"
#include <cstdint>

// In this file I will create multiple patterns by using loops in order to master them :)

// FUNCTIONS DECLARATIONS

void loop_1(int height);
void loop_2(int height);
void loop_3(int height);
void loop_for_spaces(int height);
void loop_for_numbers_on_row(int numbers);
void loop4(int height);
void loop5(int height);
void loop5_copy(int height);
void loop6(int height);
void loop7(int height);
void loop8(int height);
void loop9(int height);
void loop10(int height);
void loop11(int height);
void loop12(int height);
int test();
int veryTalkativeFunction();
int getValueFromUser();
void printDoubleValueFromUser(int num);
int32_t sumTo(int32_t value);
void fizzBuzzPop(int32_t number);

int main()
{
	// Write a program that prints out the letters a through z along with their ASCII codes. Use a loop variable of type char.

	int8_t c { 'a' };

	while (c <= 'z')
	{
		std::cout << c << ' ' << static_cast<int16_t>(c) << '\n';
		++c;
	}
	std::cout << '\n';

	/*
	5 4 3 2 1
    4 3 2 1
    3 2 1
    2 1
    1
	*/

	
	int32_t rowMax{ 5 };
	int32_t rowCount{ rowMax};
		
	while (rowCount > 0)
		{
			int32_t rowContents{ rowCount };
			while (rowContents >= 1)
			{
				std::cout << rowContents << ' ';
				--rowContents;
			}
			std::cout << '\n';
			--rowCount;
		}

    /*
	        1
          2 1
        3 2 1
      4 3 2 1
    5 4 3 2 1
    */
	int32_t rowMax2{ 5 };
	int32_t rowCount2{ rowMax2 };

	while (rowCount2 > 0)
	{
		int32_t rowSpaces{ rowCount2 };
		int32_t rowContents{ rowMax2 - rowCount2 + 1 };

		while (rowSpaces >= 1)
		{
			std::cout << "  ";
			--rowSpaces;
		}
		while (rowContents >= 1)
		{
			std::cout << rowContents << ' ';
			--rowContents;
		}
	
		std::cout << '\n';
		--rowCount2;

	}
	std::cout << '\n';


	// Write a for loop that prints every even number from 0 to 20.

	for (int32_t i{ 2 }; i <= 20; i += 2)
	{
		std::cout << i << '\n';
	}
	std::cout << '\n';


	int32_t result{ sumTo(5) };
	std::cout << result << '\n';
	std::cout <<'\n';

	fizzBuzzPop(150);




	/* 
	std::cout << "LOOP 1: \n";
	loop_1(5);

	std::cout << "LOOP 2: \n";
	loop_2(5);

	std::cout << "LOOP 3: \n";
	loop_3(5);

	std::cout << "LOOP 4: \n";
	loop4(5);
	std::cout << '\n';

	std::cout << "LOOP 5: \n";
	loop5(5);

	std::cout << "LOOP 5 (COPY): \n";
	loop5_copy(5);

	std::cout << "LOOP 6: \n";
	loop6(5);

	std::cout << "LOOP 7: \n";
	loop7(5);

	std::cout << "LOOP 8: \n";
	loop8(5);

	std::cout << "LOOP 9: \n";
	loop9(5);

	std::cout << "LOOP 10: \n";
	loop10(5);

	std::cout << "LOOP 11: \n";
	loop11(10);

	std::cout << "LOOP 12: \n";
	loop12(5);

	int i = 1;
	int j = ++i;
	std::cout << "VALUE OF I:" << i << '\n' << "VALUE OF J:" << j << '\n'; // I = 2, J = 2
	// (i is 2, j is 2)

	int x = 1;
	int z = x++;
	std::cout << "VALUE OF X:" << x << '\n' << "VALUE OF Z:" << z << '\n'; // X = 2; Z =1
	//(x is 2, z is 1)

	int num1 = 1;

	std::cout << "VALUE OF ++NUM1:" << ++num1 << '\n';// result is 2

	int num2 = 1;

	std::cout << "VALUE OF ++NUM2:" << num2++ << '\n';// result is 1

	// BUT

	int num3 = 1;
	++num3;
	std::cout << "VALUE OF ++NUM3:" << num3 << '\n'; // result is 2

	int num4 = 1;
	num4++;
	std::cout << "VALUE OF ++NUM4:" << num4 << '\n'; // result is 2
	std::cout << '\n';

	//int number{ test() };
	//std::cout << number +2;
	int number{ veryTalkativeFunction() };
	std::cout << "The number from the function is :" << number << '\n';
	std::cout << '\n';

	// whatever();
	printDoubleValueFromUser(getValueFromUser());
	*/

 }


