#include <iostream>
#include <iomanip> // for std::setw (which sets the width of the subsequent output)

int getInteger();

bool isPrime(int x)
{
    for (int i = 2; i < x; ++i) // INITIAL MISTAKE WHICH CAUSED UNDEFINED BEHAVIOUR X < I
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
        int x{ getInteger()};
		int y{ getInteger() };
}
        /*
		std::cout << x << " + " << y << " is " << x + y << '\n';
    
            std::cout << std::left; // left justify output
            std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
            std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
            std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
            std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
            std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
            std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
            std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
            std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
            std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

            return 0;
      
   int x{};
 
   do
    {
        std::cout << "Enter an integer between 0 and 9: ";
        std::cin >> x;

    } 
   while (x < 0 || x > 9); 
     
    if (isPrime(x)) //== true) // de intrebat                     //
        std::cout << "The digit you've entered is prime. \n";     // true
    else
        std::cout << "The digit you've entered is not prime. \n"; // false 

    char ch{ 97 };
    //++ch;
    std::cout << ch++ ;

}
*/




