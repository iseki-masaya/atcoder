#include <iostream>
#include <cmath>
#include <vector>
 
int main(int argc, const char * argv[])
{
    int From,To;
	int count = 0;
    std::cin >> From;
	std::cin >> To;
 
	int SubValue = std::abs(To - From);
 
	while(SubValue)
	{
		if(SubValue - 10>=-2)
		{
			SubValue = std::abs(SubValue -10);
			count++;
		}
		else if(SubValue - 5>=-2)
		{
			SubValue = std::abs(SubValue -5);
			count++;
		}
		else if(SubValue - 1>=0)
		{
			SubValue = std::abs(SubValue -1);
			count++;
		}
	}
 
	std::cout << count <<'\n';
    
    return 0;
}