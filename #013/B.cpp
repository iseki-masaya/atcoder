#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void input(vector<vector<int> > &list)
{
	int size;
	cin >> size;
	
	for (int i=0; i<size; ++i) {
		vector<int> workVec(3);
		for (vector<int>::iterator it = workVec.begin(); it != workVec.end(); ++it) {
			cin >> *it;
		}
		list.push_back(workVec);
		workVec.clear();
	}
}

int solve(vector<vector<int> >&list)
{
	int volume = 1;
	
	for (vector<vector<int> >::iterator it = list.begin(); it != list.end(); ++it) {
		sort((*it).begin(), (*it).end());
	}
	
	int max = 0;
	for (int i=0; i<3; ++i) {
		for (int j=0; j<list.size(); ++j) {
			if (max < list[j][i]) {
				max = list[j][i];
			}
		}
		volume *= max;
	}
	
	return volume;
}

int main(int argc, const char * argv[])
{
	vector<vector<int> >list;
	input(list);
	
	int volume = solve(list);
	cout << volume << endl;
	return 0;
}

