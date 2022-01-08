/* problem 24 finds the millionth 
lexicographic permutation 
of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9*/

#include <iostream>

void perms()
{
   size_t temp, i, j;
   const int LENGTH{ 10 };
   uint8_t array[11]{ "0123456789" };
   //because million fits in 32
   for (uint32_t count = 1; count < 1000000; ++count)
   {
       //finding right side element that is 
       //bigger than previous element
       for (i = LENGTH - 1; i > 0 && array[i - 1] >= array[i]; --i)
       { }
       //finding right side smallest 
       //element that is greater than i
       for (j = LENGTH - 1; j > 0 && array[j] <= array[i - 1]; --j)
       { }

       //swapping i and j
       temp = array[i - 1];
       array[i - 1] = array[j];
       array[j] = temp;

       //sorting subarray till the first i or j position,,
       //j is rightside j is leftside
       for (j = LENGTH - 1; i < j; i++, j--)
       {
           temp = array[i];
           array[i] = array[j];
           array[j] = temp;
       }
   }
   std::cout << array;
}

int main()
{
   perms();
}
