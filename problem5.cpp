#include <iostream>

int LowestCommonMul(int limit)
{
    int product = 2;
    if (limit < 1) { return 0; }
    if (limit < 2) {return 1;}
   for (int i = 2; i <= limit; ++i)
   {
      for (int j = 2; j < i; ++j)
      {
          if (product % i != 0)  //if contains prime factor
          {
               if (((product * j) % i) == 0)
              {
                  product *= j;
              }
          }
       }
  }
   return product;
}

int main()
{
    std::cout << LowestCommonMul(20);
}