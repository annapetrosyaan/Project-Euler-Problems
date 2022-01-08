/* problem 12 counts the index of first
fibonacci number that has 1000 digits*/

#include <iostream>

void bigFibonacci()
{
    const int LIMIT{ 1000 };
    long int fib[LIMIT]{ 0 }, n1[LIMIT]{ 0 }, n2[LIMIT]{ 0 };
    int carry{}, temp{}, indexCount{ 2 };
    // n-2 and n-1 == 1
    n2[0] = n1[0] = 1;
    while (1)
    {
        for (int i = 0; i < LIMIT; ++i)
        {
            temp = n2[i] + n1[i] + carry;
            carry = 0;
            if (temp > 9)
            {
                fib[i] = temp % 10;
                carry = temp / 10;
            }
            else
            {
                fib[i] = temp;
            }
        }
        //forwarding n-2 to n-1 and n-1 to fib[i]
        for (int i = 0; i < LIMIT; ++i)
        {
            n2[i] = n1[i];
            n1[i] = fib[i];
        }

        indexCount++;
       //checking if we reached to 1000 digit
        if (fib[LIMIT - 1] != 0)
        {
            break;
        }
    }

    /*  typing the result backwards
    for(int i=LIMIT-1;i>=0;--i)
     {
         std::cout<<fib[i];
     } */
   std::cout << "Index of the first 1000 digit Fibonacci number is = " << indexCount;
}

int main()
{
  bigFibonacci();
}