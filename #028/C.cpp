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

vector<int> cnt;
vector<vector<int> > g;

int dfs(int p, int v) {
    int res = 0;
    for (int u: g[v]) {
        if (u != p) {
            res += dfs(v, u);
        }
    }
    return cnt[v] = res + 1;
}

int main() {
    int N;
    cin >> N;

    g.clear(); g.resize(N);

    for (int i=1; i<N; ++i) {
        int p;
        cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    cnt.clear(); cnt.resize(N,-1);
    dfs(-1, 0);

    for (int i=0; i<N; ++i) {
        int ans = 0;
        int ac = cnt[i];
        for (int u: g[i]) {
            int c = cnt[u];
            if (c > ac)
                ans = max(ans, N-ac);
            else
                ans = max(ans, c);
        }
        cout << ans << endl;
    }
    return 0;
}