#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
 
const int MAX_W = 501;
const int MAX_H = 501;
const int INF = 1e+7;
 
int Width,Height;
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};
char way[MAX_W][MAX_H];
int dist[MAX_W][MAX_H];
int start[2];
 
double getBright(char chr,int t){
	return (double)(chr - '0')*pow(0.99, t);
}
 
bool checkBright(double limit){
	queue<pair<int,int> > pos;
	pos.push(pair<int,int>(start[0],start[1]));
	//init dist
	for (int i=0; i<MAX_H; i++) {
		fill(dist[i], dist[i] + MAX_W, INF);
	}
	dist[start[0]][start[1]] = 1;
	
	while (!pos.empty()) {
		int x = pos.front().first;
		int y = pos.front().second;
		int t = dist[x][y];
		pos.pop();
		
		for (int i=0; i<4; i++) {
			int dx = x + vx[i];
			int dy = y + vy[i];
			
			if (dist[dx][dy] != INF || way[dx][dy] == '#' || dx<0||Width<=dx || dy<0||Height<=dy) continue;
			
			if (way[dx][dy] == 'g') {
				return true;
			}
			
			if (isdigit(way[dx][dy]) && limit <= getBright(way[dx][dy], t) ) {
				dist[dx][dy] = t + 1;
				pos.push(pair<int,int>(dx,dy));
			}
		}
	}
	return false;
}
 
int main(int argc, const char * argv[])
{
	//get input
	cin >> Height >> Width;
	for (int y=0; y<Height; y++) {
		for (int x=0; x<Width; x++) {
			cin >> way[x][y];
			if (way[x][y] == 's') {
				start[0] = x;
				start[1] = y;
			}
		}
	}
 
	if (!checkBright(0.0)) {
		//cannot reach the goal
		cout << -1 << endl;
	}
	else{
		//binary serach
		double low = 0.0; double high = 10.0;
		double mid = 0;
		while (high-low > 1e-10) {
			mid = (high + low)/2;
			if (checkBright(mid)) {
				low = mid;
			}
			else{
				high = mid;
			}
		}
		mid = (high + low)/2;
		cout.precision(12);
		cout << mid << endl;
	}
	
    return 0;
}