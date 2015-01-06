#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

/*---------------------------------------------*/
//explit
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
//stringからintへの変換
int stringToInt(string str){
	int number;
	stringstream ss;
	ss << str;
	ss >> number;
	return number;
}
//素数かどうか判別
bool isPrime(int n){
	if(n<2)
		return false;
	else if(n==2)
		return true;
	if(n%2==0)
		return false;
	for (int i=3; i*i<=n; i+=2)
		if(n%i==0)
			return false;
	return true;
}
//最大公約数
int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
		c = a; a = b%a;  b = c;
  }
  return b;
}
int gcdr ( int a, int b )
{
  if ( a==0 ) return b;
  return gcdr ( b%a, a );
}
//最小公倍数
int lcm (int a, int b)
{
	return (a*b)/gcd(a,b);
}

/*---------------------------------------------*/

int main(int argc, const char * argv[])
{
	
	
    return 0;
}

