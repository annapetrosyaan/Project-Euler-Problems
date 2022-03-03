#include <iostream>
#include "stringImpl.h"

int main()
{
   myString str(3,'h');
   str.insert(3,"ello");
   std::cout<< str << "\n";
   std::cout<< str.at(1) << "\n";
   std::cout<< str.size() << "\n";
   std::cout<< str.find('v') << "\n";
   myString string(str);
   std::cout<< string << "\n";
   myString sum = str + string;
   std::cout<< sum << "\n";
   str.pushBack('a');
   std::cout<<str<< "\n";
}