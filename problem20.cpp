/* Factorial digit sum
the example is on 100!*/

#include <iostream>

int mul(int x, int* arr, int size)
{
   int temp{};
   for (int i = 0; i < size; ++i)
   {
      int product = arr[i] * x + temp;
      arr[i] = product % 10;
      temp = product / 10;
   }
   while (temp)
   {
      arr[size] = temp % 10;
      temp /= 10;
      size++;
   }
   return size;
}

int fac(int n)
{
   const int MAX{ 1000 };
   int result[MAX]{};
   result[0] = 1;
   int size{ 1 };
   int sum{};
   for (int i = 2; i <= n; ++i)
   {
       size = mul(i, result, size);
   }
   std::cout << "Factorial of given number is \n";
   for (int i = 0; i < size; ++i)
   {
       sum += result[i];
   }
   return sum;
}

int main()
{
  std::cout << fac(100);
}