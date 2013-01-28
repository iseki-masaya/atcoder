#include <iostream>
using namespace std;
 
int main(int argc, const char * argv[])
{
	//get input
	int N,M;
	cin >> N >> M;
	int listenMusic[M];
	for (int i=0; i<M; i++) {
		cin >> listenMusic[i];
	}
	//make cd position array and cd
	//cdCase has cd case number and it reduced the amount of calculation
	//cd has cd number and it shows answer
	int cd[N+1];
	int cdCase[N+1];
	for (int i=0; i<N+1; i++) {
		cd[i] = i;
		cdCase[i] = i;
	}
	//simulate
	int tmp;
	int pos;
	for (int i=0; i<M; i++) {
		//set parameter
		tmp = cd[0];
		pos = cdCase[listenMusic[i]];
		
		//change position
		cd[0] = listenMusic[i];
		cd[pos] = tmp;
		
		//save postition
		cdCase[listenMusic[i]] = 0;
		cdCase[tmp] = pos;
	}
	//output the answer
	for (int i=1; i<N+1; i++) {
		cout << cd[i] << endl;
	}
	
    return 0;
}