#include <iostream>
#include <string>
#include <cmath>
#include <vector>
 
int main(int argc, const char * argv[])
{
	int nameAmount=0;
	int blockAmount;
	int i,j,k;
 
	std::cin >> nameAmount;
	std::cin >> blockAmount;
 
	std::string name;
	std::cin >> name;
	std::string tmpName = name;
 
	std::string kit;
	std::cin >> kit;
 
	std::string tmpKit = kit;
	int count =0;
	bool frag = true;
 
	for(i=0;i<nameAmount;i++)
	{
		for(j=0;j<blockAmount;j++)
		{
			if(name[i] == kit[j])
			{
				name[i] = '/';
			}
		}
	}
 
	for(i=0;i<nameAmount;i++)
	{
		if(name[i]!='/')
		{
			std::cout << "-1" << '\n';
			return 0;
		}
	}
 
	name = tmpName;
 
	while(frag)
	{
		for(i=0;i<nameAmount;i++)
		{
			for(j=0;j<blockAmount;j++)
			{
				if(name[i] == kit[j])
				{
					name[i] = '/';
					kit[j] = '*';
				}
			}
		}
 
		frag = false;
 
		for(i=0;i<nameAmount;i++)
		{
			if(name[i]!='/')
				frag = true;
		}
		kit = tmpKit;
		count++;
	}
 
	std::cout << count << '\n';
	std::cin >> name;
	/*
	int hitNum[50];
	for(i=0;i<50;i++)
	{
		hitNum[i]=0;
	}
 
	for(i=0;i<nameAmount;i++)
	{
		for(j=0;j<blockAmount;i++)
		{
			if(name[i] == kit[j])
				hitNum[i]++;
		}
	}
 
	for(i=0;i<nameAmount;i++)
	{
		if(hitNum[i]==0)
			std::cout << '-1' << '\n';
	}
	*/
 
	/*
	int nameSpell[26];
	int blockSpell[26];
	
	std::string Alpha = "ABCDEFGHIJKLMNOPQRTUVWXYZ";
 
	for(i=0;i<26;i++)
	{
		nameSpell[i] = 0;
		blockSpell[i] = 0;
	}
 
	for(i=0;i < nameAmount;i++)
	{
		for(j=0;j < 26;j++)
		{
			if(name[i] == Alpha[j])
				nameSpell[j]++;
		}
	}
 
	for(i=0;i < blockAmount;i++)
	{
		for(j=0;j < 26;j++)
		{
			if(kit[i] == Alpha[j])
				blockSpell[j]++;
		}
	}
	*/
	
}