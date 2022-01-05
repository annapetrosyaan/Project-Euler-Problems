/*Program which finds the largest palindromic 
product of two 3digit number*/

#include <iostream>
#include <cmath>

int palProduct();

int main() {
    std::cout << palProduct();
}

int palProduct()
{
   int upLimit = pow(10, 3) - 1;
   int lowLimit = 1 + upLimit / 10;
   int maxProduct{};
   for (int i = upLimit; i >= lowLimit; --i)
   {
       for (int j = i; j >= lowLimit; --j)
       {
           int product = i * j;
           int number = product;
           int reverse{};
           /* counting reverse the same number to compare
           and see if its palindrome or not */
           while (number != 0)
           {
               reverse = reverse * 10 + number % 10;
               number /= 10;
           }
           if (product == reverse && product > maxProduct)
           {
               maxProduct = product;
           }
       }
   }
   return maxProduct;
}
