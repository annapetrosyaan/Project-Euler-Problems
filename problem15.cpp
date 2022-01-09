/* problem 15 counts how many routes are there through a 20×20 grid 
with only being able to move to the right and down*/

#include <iostream>

void LatticePath()
{
    long long int grid [21][21]{};
    //initializing every element to 1
    for (int i = 0; i <21; ++i)
    {
        for (int j = 0; j < 21; ++j)
        {
            grid[i][j] = { 1 };
        }
    }

    //to go to bottom right = left + top
    for (int i = 1; i < 21; ++i)
    {
        for (int j = 1; j < 21; ++j)
        {              //left,,
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }
    std::cout << grid[20][20] << std::endl;
}

int main()
{
    LatticePath();
}