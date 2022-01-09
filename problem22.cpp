/* problem 22
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
What is the total of all the name scores in the file?  */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


void NameScores()
{
	std::ifstream read("p022_names.txt");
	if (!(read.is_open())) { std::cout << "CANT OPEN FILE"; }
	
	std::vector<std::string>names{};
	std::string token;

	// reading till the , and adding to vector
	while (getline(read, token, ','))
	{
		names.push_back(token);
	} 

	//sorting vector of names
	std::sort(names.begin(), names.end()) ;

	int countInd{0};
	unsigned int bigAnswer{0};

	//getting index and ascii values of each element
	//for (auto it : names) didnt worked
	for (auto it = names.begin(); it != names.end(); ++it)
	{
		countInd++;
		//copying name from token without its " "-s
		std::string name {(*it).begin() + 1, (*it).end() - 1};

        // making letter to number
		int total{0};
		for (std::string::iterator iter = name.begin(); iter != name.end(); ++iter)
		{
			// a=65 => a=1 and b=2  so *iter-64
			total += (*iter- 64);
		}
		bigAnswer += (total * countInd);
	}
	std::cout <<" "<< bigAnswer;
}

int main()
{
	NameScores();
}