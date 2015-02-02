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

double memo[105];
double prob[105][105][105];

double f(int n) {
    double &r = memo[n];
    if (r == r)
        return r;
    if (n == 1)
        return r = 0;

    double winp = 0, drawp = 0;
    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=n-i; ++j) {
            int k = n - i - j;
            double t = prob[i][j][k];

            vector<int> a = {i,j,k};
            sort(a.begin(), a.end());

            if (a[1] == 0) {
                drawp += t;
            } else if (a[0] == 0) {
                winp += t*f(a[1]);
            } else if (a[0] < a[1]) {
                winp += t*f(a[0]);
            } else if (a[1] < a[2]) {
                winp += t*f(a[0]);
            } else {
                drawp += t;
            }
        }
    }

    double ans = 0.0;
    double d = 1.0 - drawp;
    double s = 1.0;
    for (int i=1; i<=100; ++i) {
        ans += i*d*s + winp*s;
        s *= drawp;
    }
    return r = ans;
}

double solve(int n) {
    memset(prob, 0, sizeof(prob));
    prob[0][0][0] = 1.0;
    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=n; ++j) {
            for (int k=0; k<=n; ++k) {
                double t = prob[i][j][k];
                prob[i+1][j][k] += t/3.0;
                prob[i][j+1][k] += t/3.0;
                prob[i][j][k+1] += t/3.0;
            }
        }
    }
    memset(memo, -1, sizeof(memo));
    return f(n);
}

int main() {
    int N;
    cin >> N;
    double ans = solve(N);
    printf("%.10f\n", ans);
}