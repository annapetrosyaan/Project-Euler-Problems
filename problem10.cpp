/*Program to find the sum of all prime 
numbers below 2million*/

#include <iostream>
#include <cmath>

bool isPrime(int num);
void sum();

int main()
{
   sum();
   return 0;
}

bool isPrime(int num)
{
   if (num < 2)
       return false;
   if (num == 2)   //only one even number can pass
       return true;
   if (!(num % 2))  //else other even numbers are false
       return false;
    /* to not check all numbers:we are checking
    only sqrt of that number,,
    checking only odd numbers less than sqrt(num)*/
   for (int i = 3; i <= sqrt(num); i += 2)
       if (!(num % i))
           return false;
   return true;
}

void sum() {
   long long sum = 2;  //initilaizing sum with 2,onliest even prime number
   for (int i = 3; i < 2000000; i += 2)    //skip even/zuyg number
   {
       if (isPrime(i))
       {
           sum += i;
       }
   }
   std::cout << sum << std::endl;
}