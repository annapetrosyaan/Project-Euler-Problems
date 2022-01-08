#include <iostream>
#include <cmath>

void PythagoreanTriplet()
{
   int a, b, c, c2;
   for (a = 1; a <= 1000; a++)
   {
       for (b = 1; b <= 1000; b++)
       {
           c2 = a * a + b * b;
           c = sqrt(c2);
           if (c * c == c2 && a + b + c == 1000 && a < b)
           {
              std::cout << "a=" << a << "" << "b=" << b << "" << "c=" << c << std::endl;
              std::cout << "product of triplets==" << a * b * c;
           }
       }
   }
 }

int main()
{
   PythagoreanTriplet();
}