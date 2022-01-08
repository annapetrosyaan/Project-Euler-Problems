/* problem 12  finds first triangular
number which has 500 divisors*/

#include <iostream>
#include <cmath>

void TriangleNum()
{
   int triNum{}, natNum{}, divisor{};
   while (1)
   {
       natNum++;
       triNum += natNum;
       divisor = 0;
       //looping till numbers square root
       for (int i = 1; i < (int)floor(sqrt(triNum)); ++i)
       {
           if (triNum % i == 0)
           {
               divisor += 2;
           }
           //check for perfect triangle square
           if ((int)floor(sqrt(triNum)) * (int)floor(sqrt(triNum)) == triNum)
           {
               divisor--;
           }
       }
       if (divisor > 500) break;
   }
   std::cout << "Triangular number = " << triNum << std::endl;
   std::cout << "Divisors = " << divisor << std::endl;
}

int main()
{
   TriangleNum();
}