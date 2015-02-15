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

vector<int> h;
vector<vector<int> > g;

int dfs(int par, int v) {
    int res = 0;
    for (int u: g[v])
        if (u != par)
            res += dfs(v, u);
    if (res != 0 || h[v])
        ++res;
    return res;
}

int main() {
    int n,x;
    cin >> n >> x;
    --x;
    h.clear(); h.resize(n);
    g.clear(); g.resize(n);

    for (int i=0; i<n; ++i)
        cin >> h[i];
    for (int i=0; i<n-1; ++i) {
        int a,b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << max(0, 2*(dfs(-1, x)-1)) << endl;
}