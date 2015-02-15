#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>
#include <memory>

const long long LINF = (5e18);
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

long long mx = 1e10;

void calc(double A,double B, double md, double &h, double &w) {
	double rad = (double)md / mx * M_PI_2;
	double s = sin(rad);
	double c = cos(rad);
	h = A*c + B*s;
	w = A*s + B*c;
}

string solve_bi(double A, double B, double C, double D) {
	if ( A < C && B < D )
		return "YES";
	long long ub = mx, lb = 0;
	double h = 0.0,w = 0.0;
	for (int i=0; i<200; ++i) {
		long long md = (ub + lb) / 2;
		calc(A, B, md, h, w);
		if ( h < C && w < D )
			return "YES";
		if (h > C)
			ub = md;
		else
			lb = md;
	}
	return "NO";
}

int main() {
	int a,b,N;
	cin >> a >> b >> N;
	int	A = min(a, b);
	int B = max(a, b);
	for (int i=0; i<N; ++i) {
		int c,d;
		cin >> c >> d;
		int C = min(c, d);
		int D = max(c, d);
		cout << solve_bi(A, B, C, D) << endl;
	}
}