#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Direct
{
	int dx;
	int dy;
};

void init(map<string,Direct> &dirList)
{
	Direct d;
	d.dx = 1 ; d.dy = 0 ;
	dirList["R"] = d;
	
	d.dx = -1; d.dy = 0 ;
	dirList["L"] = d;
	
	d.dx = 0 ; d.dy = -1;
	dirList["U"] = d;
	
	d.dx = 0 ; d.dy = 1 ;
	dirList["D"] = d;
	
	d.dx = 1 ; d.dy = -1;
	dirList["RU"] = d;
	
	d.dx = 1 ; d.dy = 1 ;
	dirList["RD"] = d;
	
	d.dx = -1; d.dy = -1;
	dirList["LU"] = d;
	
	d.dx = -1; d.dy = 1 ;
	dirList["LD"] = d;
}

void input(int &x,int &y,string &direction,vector<string> &list)
{
	string work;
	cin >> x >> y >> direction;
	for (int i=0; i<9; ++i) {
		cin >> work;
		list.push_back(work);
	}
}

void increment(int &x,int &y,int maxX,int maxY,Direct &dir)
{
	if (x == maxX - 1 && dir.dx == 1) {
		dir.dx = -1;
	}
	else if (x == 0 && dir.dx == -1) {
		dir.dx = 1;
	}
	
	if (y == maxY - 1 && dir.dy == 1) {
		dir.dy = -1;
	}
	else if(y == 0 && dir.dy == -1) {
		dir.dy = 1;
	}
	
	x += dir.dx;
	y += dir.dy;
}

string solve(int &x,int &y,string &direction,vector<string> &list,map<string,Direct> &dirList)
{
	string ans = "";
	int maxY = (int)list.size();
	int maxX = (int)list.at(0).size();
	Direct dir = dirList[direction];
	
	for (int i=0; i<4; ++i) {
		ans += list[y][x];
		increment(x,y,maxX,maxY,dir);
	}
	return ans;
}

int main()
{
	map<string,Direct> dirList;
	init(dirList);
	
	int x,y;
	string direction;
	vector<string> list;
	
	input(x,y,direction,list);
	--x;--y;
	
	string ans = solve(x,y,direction,list,dirList);
	
	cout << ans << endl;
	
	return 0;
}
