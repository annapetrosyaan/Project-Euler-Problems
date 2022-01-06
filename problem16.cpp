/*Program that allows you to know 
the sum || power of big numbers
for example pow(20,1000) */

#include <iostream>

int mul(int, int[], int);
void PowAndSum(int, int);

int main()
{
  int base = 20;
  int expo = 1000;
  PowAndSum(base, expo);
}

/* multiplies x with the number 
represented in array*/

int mul(int x, int* arr, int size)
{
  int tool = 0;
  for (int i = 0; i < size; ++i)
   {
     int product = arr[i] * x + tool;
     arr[i] = product % 10;
     tool = product / 10;
   }
   while (tool)
   {
     arr[size] = tool % 10;
     tool /= 10;
     size++;
   }
 return size;
}

/*finds the power of x and after that 
finds the sum*/

void PowAndSum(int x, int n)
{
  if (n == 0)
  {
   std::cout << "smth went wrong";
  }
  const int MAX{ 10000 };
  int sum{};
  int result[MAX];
  int size = 0;
  int tmp = x;
  while (tmp != 0)
  {
     result[size++] = tmp % 10;
     tmp /= 10;
  }
  for (int i = 2; i <= n; ++i)
  {
     size = mul(x, result, size);
  }
  for (int i = 0; i < size; ++i)
  {
     sum += result[i];
  }
  std::cout << sum;
}