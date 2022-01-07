/* problem 6th which counts the 
difference between the sum of the
squares of the first 100 natural 
numbers and the square of the sum*/

#include <iostream>
#include <cmath>

int SumSquareDiff()
{
   const int n = 100;
   long int sum1{};
   long int sum2{};
   int diff{};
   for (int i = 1; i <= n; ++i)
   {
       sum1 += pow(i, 2);
       sum2 += i;
   }
   sum2 *= sum2;
   diff = sum2 - sum1;
   return diff;
}

int main()
{
   std::cout << SumSquareDiff();
}