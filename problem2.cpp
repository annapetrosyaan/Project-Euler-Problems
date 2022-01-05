/* Finding the sum of even numbers in fibonacci 
series which ends on 4million*/

#include <iostream>

int even_sum();

int main()
{
    std::cout << even_sum();
    return 0;
}

int even_sum()
{
    long long int limit{ 4000000 };
    long long int f1{ 0 }, f2{ 2 };
    long long int sum = f1 + f2;
    while (f2 <= limit)
    {
        long long int f3 = 4 * f2 + f1;
        if (f3 > limit)
        {
            break;
        }
        f1 = f2;
        f2 = f3;
        sum += f3;
    }
    return sum;
}