/*Program that finds the sum all the multiples
of 3 and 5 below 1000*/

#include <iostream>

int sum_counter();

int main() {
    std::cout << sum_counter();
}

int sum_counter()
{
    int limit = 1000;
    int sum{};
    for (int i = 1; i < limit; ++i)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    return sum;
}