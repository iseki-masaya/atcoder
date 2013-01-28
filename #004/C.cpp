#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;
 
long long int memo = 0;
 
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
long long int stringToInt(string str){
	long long int number;
	stringstream ss;
	ss << str;
	ss >> number;
	return number;
}
long long int gcd(long long int large, long long int small) {
	if (small == 0)
		return large;
	return gcd(small, large % small);
}
/*---------------------------------------------*/
int main(int argc, const char * argv[])
{
	string input;
	vector<string> value;
	long long int X,Y;
	string delim = "/";
	cin >> input;
	value = split(input, delim);
	X = stringToInt(value[0]);
	Y = stringToInt(value[1]);
	long long int g;
	g = gcd(max(X,Y),min(X,Y));
	X /= g; Y /= g;
	
	long long int min = 2*floor(X/Y)-100;
	if (min<0) min = 1;
	long long int max = 2*ceil((double)(X/Y)+100);
	long long int sum;
	long long int M;
	bool isImpossible = true;
	
	for (long long int i=min; i<max; i++) {
		sum = i*(i+1);
		sum = sum/2;
		if (i % Y == 0){
			M = sum - X*(i/Y);
			if(0<M && M<=i){
				cout << i << " " << M << endl;
				isImpossible = false;
			}
		}
	}
	if(isImpossible)
		cout << "Impossible" << endl;
	
    return 0;
}
