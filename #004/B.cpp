#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(int argc, const char * argv[])
{
	// get input
	int N;
	cin >> N;
	int d[N];
	for (int i=0; i<N; i++) {
		cin >> d[i];
	}
	
	//sort d
	sort(d,d+N);
	
	//cals max
	int maxDist = 0;
	for (int i=0; i<N; i++) {
		maxDist += d[i];
	}
	
	//calc min
	int tmp = 0;
	for (int i=0; i<N-1; i++) {
		tmp += d[i];
	}
	int minDist;
	minDist = max(d[N-1]-tmp,0);
	
	cout << maxDist << endl << minDist << endl;
    return 0;
}
