#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>

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
/*---------------------------------------------*/

int next_index(int x)
{
	if (x==2) {
		x = 0;
	}
	else{
		++x;
	}
	return x;
}
int prev_index(int x)
{
	if (x==0) {
		x = 2;
	}
	else{
		--x;
	}
	return x;
}

int main(int argc, const char * argv[])
{
	vector<int> cardbortdSize(3);
	for (vector<int>::iterator it = cardbortdSize.begin(); it != cardbortdSize.end(); ++it) {
		cin >> *it;
	}
	vector<int> burdenSize(3);
	for (vector<int>::iterator it = burdenSize.begin(); it != burdenSize.end(); ++it) {
		cin >> *it;
	}
	
	int comb_map[3][3];
	for (int i=0; i<3; ++i) {
		for (int j=0; j<3; ++j) {
			comb_map[i][j] = cardbortdSize.at(i)/burdenSize.at(j);
		}
	}
	
	int work=1,max=0;
	int k;
	for (int i=0; i<3; ++i) {
		k = i;
		for (int j=0; j<3; ++j) {
			work *= comb_map[j][k];
			
			k = next_index(k);
		}
		if (max < work) {
			max = work;
		}
		work = 1;
		//逆
		k = i;
		for (int j=0; j<3; ++j) {
			work *= comb_map[j][k];
			
			k = prev_index(k);
		}
		if (max < work) {
			max = work;
		}
		work = 1;
	}
	
	cout << max << endl;
	
	return 0;
}

