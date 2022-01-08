/*problem 19 - outputs the count odSf undays fell on the first of  
the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)*/

#include <iostream>

int CountSunday()
{
   int daysOfMonths[12]{ 31,   // jan
                          29,  // feb        
                          31,  // mar
                          30,  // ap
                          31,  // may
                          30,  // june
                          31,  // july
                          31,  // aug
                          30,  // sept
                          31,  // oct
                          30,  // noy
                          31,  // dec
    };
   int sunCount{ 0 }, month, year, dayOfWeek{ 1 }; //monday 1/7

    for (month = 1; month <= 12; ++month)
    {
       //starting from monday
       dayOfWeek += (daysOfMonths[month - 1] % 7);
       if (dayOfWeek > 7)
       {
           dayOfWeek = (0 + dayOfWeek % 7);
       }
    }  

    //counting all sundays
    for (year = 1901; year <= 2000; ++year)
    {
        //checking for leap year by century or its normal year
         //1st for century 2nd for leap year
        if (((year % 100 == 0) && (year % 400 == 0)) || (year % 4 == 0))
        {
            daysOfMonths[1] = 29; //leap
        }
        else
        {
            daysOfMonths[1] = 28; //regular
        }

        for (month = 1; month <= 12; ++month)
        {
            //starting from monday
            dayOfWeek += (daysOfMonths[month - 1] % 7);
            if (dayOfWeek > 7)
            {
                dayOfWeek = (0 + dayOfWeek % 7);
            }
            else if (dayOfWeek == 7)
            {
                sunCount++;
            }
        }
    }
    return sunCount;
}



int main()
{
    std::cout << CountSunday();
}