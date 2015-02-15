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

vector<vector<int> > m;
vector<bool> used;

void dfs(int v) {
    used[v] = true;
    for (int i=0; i<m[v].size(); ++i) {
        int u = m[v][i];
        if (!used[u])
            dfs(u);
    }
}

int solve(vector<vector<int> > &m) {
    used.clear(); used.resize(m.size(), false);
    int ans = 0;
    for (int i=0; i<m.size(); ++i) {
        if (used[i])
            continue;
        ++ans;
        dfs(i);
    }
    return ans - 1;
}

int main() {
    int N,M;
    cin >> N >> M;
    m.clear(); m.resize(N);
    for (int i=0; i<M; ++i) {
        int a,b;
        cin >> a >> b;
        --a, --b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    cout << solve(m) << endl;
}