#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
 
/*---------------------------------------------*/
vector<string> split(string str, string delim)
{
    vector<string> result;
    int cutAt;
    while( (cutAt = (int) str.find_first_of(delim)) != str.npos )
    {
        if(cutAt > 0)
        {
            result.push_back(str.substr(0, cutAt));
        }
        str = str.substr(cutAt + 1);
    }
    if(str.length() > 0)
    {
        result.push_back(str);
    }
	return result;
}
int stringToInt(string str){
	int number;
	stringstream ss;
	ss << str;
	ss >> number;
	return number;
}
/*---------------------------------------------*/
int main(int argc, const char * argv[])
{
	int dayOfMonth[] = {0,31,60,91,121,152,182,213,244,274,305,335};
	//get input
	int amountOfHolyday;
	cin >> amountOfHolyday;
	if (amountOfHolyday == 0){
		cout << 2 << endl;
		return 0;
	}
	vector<int> holyday;
	for (int i=0; i<amountOfHolyday; i++) {
		vector<string> strV;
		string str;
		cin >> str;
		strV = split(str, "/");
		holyday.push_back(dayOfMonth[stringToInt(strV[0])-1] + stringToInt(strV[1]) - 1);
	}
	//sort
	sort(holyday.begin(), holyday.end());
	
	vector<bool> isHolyday(366);
	//set Sunday and Saturday
	for (int i=0; i<366; i++) {
		if(i%7==0 || i%7==6)
			isHolyday[i] = true;
		else
			isHolyday[i] = false;
	}
	//set Holyday and Substitute Holyday
	int holydayKey = 0;
	for (int i=0; i<366; i++) {
		if (i == holyday[holydayKey]) {
			int k = i;
			while (isHolyday[k]) {
				k++;
				if(k>365){
					k = 365;
					break;
				}
					
			}
			isHolyday[k] = true;
			holydayKey++;
		}
	}
	//check joints
	int continuous = 0;
	int max = 0;
	for (int i=0; i<366; i++) {
		if (isHolyday[i]) {
			continuous++;
		}
		else{
			if (max<continuous) {
				max = continuous;
			}
			continuous = 0;
		}
	}
	if (max<continuous) {
		max = continuous;
	}
	//out put the answer
	if (max < 2)
		max = 2;
	cout << max << endl;
	
	return 0;
}