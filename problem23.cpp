/*problem 23-program finds the sum of all the positive integers
which cannot be written as the sum of two abundant numbers.*/
#include <iostream>
#include <vector>

void NonAbundantNum()
{
    const int LIMIT{ 28123 };
    long int divSum{};        //if sum is greater than the number than 
    std::vector<int>abNum;    //throwing it to abundant numer vector  
    abNum.reserve(7000);
    int abIndex{ 0 };
    std::vector<int>sumAbNums;
    sumAbNums.reserve(LIMIT);
    int answer{};

    for (int i = 12; i <= LIMIT; ++i)  //starting from first abundant num
    {
        divSum = 0;
        //sum of divisors
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                divSum += j;

                if (j < (i / j))  //check if divisor is less than original num/div
                {
                    divSum += (i / j);
                }
                if (divSum > i)  //if greater than number pushing into vector
                {
                    abNum[abIndex++] = i;
                    break;
                }
            }
        }
    }
    //sum of 2 abNums is set to 1
    for (int i = 0; i < abIndex; ++i)
    {
        for (int j = 0; j < abIndex; ++j)
            if ((abNum[i] + abNum[j]) <= LIMIT)
            {
                sumAbNums[abNum[i] + abNum[j]] = 1;
            }
    }

    //counting sum of non ab nums
    for (int i = 1; i <= LIMIT; ++i)
    {
        if (sumAbNums[i] == 0)
       {
           answer += i;
       }
   }
   std::cout << answer;
}

int main()
{
   NonAbundantNum();
}