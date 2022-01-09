/* problem 14- counts the starting number under one million that 
produces the longest collatz sequence*/

#include <iostream>

void LongestColl()
{
    long start{}, answer{};
    long long sequence{};
    int terms{}; //in sequence,,highest number terms is the chain
    int savedterms{};  //save num of terms everytime its greater

    for (start = 2; start < 1000000; start++)
    {
        terms = 1; //at least 1
        sequence = start;
        while (sequence > 1)  //cannot be less than one
        {
            while (sequence % 2 == 0) //even
            {
                //dividing it till its not even
                sequence /= 2;
                terms++;
            }
            if (sequence > 1)
            {
                sequence = (sequence * 3) + 1;
                terms++;
            }
        }
        if (terms > savedterms)
        {
            savedterms = terms;
            answer = start;
        }
    }
    std::cout << "longest chain= " << savedterms << std::endl;
    std::cout << "starting from= " << answer << std::endl;
}

int main()
{
    LongestColl();
}