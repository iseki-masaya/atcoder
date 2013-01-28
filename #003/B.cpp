#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
class Less{
	public:
	bool operator()(const string& word1,const string& word2) const {
		return lexicographical_compare(word1.rbegin(), word1.rend(), word2.rbegin(), word2.rend());
	}
};
 
int main(int argc, const char * argv[])
{
	//get input
	int wordNum;
	cin >> wordNum;
	vector<string> word;
	string tmp;
	for (int i=0; i<wordNum; i++) {
		cin >> tmp;
		word.push_back(tmp);
	}
	sort(word.begin(), word.end(),Less());
	for (int i=0; i<wordNum; i++) {
		cout << word[i] << endl;
	}
    return 0;
}
