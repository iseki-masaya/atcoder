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
/*---------------------------------------------*/
struct ToLower {
    char operator()(char c) { return tolower(c); }
};
 
int main(int argc, const char * argv[])
{
	map<char,char> words;
	words.insert(make_pair('b', '1'));
	words.insert(make_pair('c', '1'));
	words.insert(make_pair('t', '3'));
	words.insert(make_pair('j', '3'));
	words.insert(make_pair('l', '5'));
	words.insert(make_pair('v', '5'));
	words.insert(make_pair('p', '7'));
	words.insert(make_pair('m', '7'));
	words.insert(make_pair('n', '9'));
	words.insert(make_pair('g', '9'));
	words.insert(make_pair('d', '2'));
	words.insert(make_pair('w', '2'));
	words.insert(make_pair('f', '4'));
	words.insert(make_pair('q', '4'));
	words.insert(make_pair('s', '6'));
	words.insert(make_pair('x', '6'));
	words.insert(make_pair('h', '8'));
	words.insert(make_pair('k', '8'));
	words.insert(make_pair('z', '0'));
	words.insert(make_pair('r', '0'));
	
	words.insert(make_pair('B', '1'));
	words.insert(make_pair('C', '1'));
	words.insert(make_pair('T', '3'));
	words.insert(make_pair('J', '3'));
	words.insert(make_pair('L', '5'));
	words.insert(make_pair('V', '5'));
	words.insert(make_pair('P', '7'));
	words.insert(make_pair('M', '7'));
	words.insert(make_pair('N', '9'));
	words.insert(make_pair('G', '9'));
	words.insert(make_pair('D', '2'));
	words.insert(make_pair('W', '2'));
	words.insert(make_pair('F', '4'));
	words.insert(make_pair('Q', '4'));
	words.insert(make_pair('S', '6'));
	words.insert(make_pair('X', '6'));
	words.insert(make_pair('H', '8'));
	words.insert(make_pair('K', '8'));
	words.insert(make_pair('Z', '0'));
	words.insert(make_pair('R', '0'));
 
	int i,j;
	int n;
	cin >> n;
	vector<string> sentense;
	string tmp;
	for(i=0;i<n;++i){
		cin >> tmp;
		sentense.push_back(tmp);
	}
	
	vector<char> number;
	char chr;
	bool isSpaced = false;
	for(i=0;i<sentense.size();++i){
		for (j=0; j<sentense[i].size(); ++j) {
			chr = sentense[i][j];
			switch (chr) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'y':
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
				case 'Y':
				case '.':
				case ',':
					continue;
			}
			number.push_back(words[chr]);
			isSpaced = false;
		}
		if(number.size()>0&&i!=sentense.size()-1&&isSpaced==false){
			number.push_back(' ');
			isSpaced = true;
		}
	}
	
	bool isChar = false;
	j = (int)number.size()-1;
	if(j<1){
		isChar = true;
	}
	while (isChar==false) {
		if(number[j]!=' '){
			isChar=true;
		}
		else if(j<1){
			break;
		}
		else {
			--j;
		}
	}
	
	for(i=0;i<j+1;++i){
		cout << number[i];
	}
	cout << endl;
	
	
    return 0;
}