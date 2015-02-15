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

typedef pair<int, int> P;

int main() {
    int N;
    cin >> N;
    int mx = 1000005;
    vector<vector<P> > tasks(mx);
    vector<int> end(N);
    for (int i=0; i<N; ++i) {
        int a,b;
        cin >> a >> b;
        tasks[a].push_back(P(i, b));
        end[i] = b;
    }

    P maxp = P(0, -INF);
    vector<P> dp(mx, maxp);
    for (int i=mx-1; i>=0; --i) {
        for (auto p: tasks[i]) {
            int c = dp[p.second].first + 1;
            if (c > maxp.first || (maxp.first == c && maxp.second > p.first) )
                maxp = P(c, p.first);
        }
        dp[i] = maxp;
    }

    cout << dp[0].first << endl;
    int now = 0;
    for (int i=1; i<dp[0].first; ++i) {
        cout << dp[now].second+1 << " ";
        now = end[dp[now].second];
    }
    cout << dp[now].second+1 << endl;
}