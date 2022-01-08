/* problem 7th finds the 
prime number in the 10001st index*/

#include <iostream>
#include <cmath>
int primes[10001]{ 0 };

bool IsPrime(int num)
{
   primes[0] = 2;
   int j{};
   while (num > primes[j] && num % primes[j] != 0)
   {
       j++;
       if (primes[j] == 0)
       {
          primes[j] = num;
          return true;
       }
   }
   return false;
}


void PrimeAt()
{
   int result{};
   int counter{ 1 }; //2 already +,,so starting from 3
   int i{ 3 };
   while (counter <= 10001)
   {
       if (IsPrime(i))
       {
           counter++;
           if (counter == 10001)
           {
               std::cout << i;
           }
       }
       i += 2; //without odds
   }
}

int main()
{
   PrimeAt();
}