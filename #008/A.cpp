#include <iostream>
#include <cmath>
#include <vector>
 
int main(int argc, const char * argv[])
{
    int Takoyaki;
    std::cin >> Takoyaki;
 
	int tenPack,one;
 
	tenPack = (int) floorf(Takoyaki/10);
	one = Takoyaki%10;
	if(one>6)
	{
		one=0;
		tenPack++;
	}
 
	int sum;
	sum = tenPack*100 + one*15;
 
	std::cout << sum <<'\n';
    
    return 0;
}
