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

long long calc(int v, vector<vector<P> > &g, long long R, long long T) {
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, v));
    vector<int> d(g.size(), INF);
    d[v] = 0;

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        if (d[p.second] < p.first)
            continue;
        for (P up: g[p.second]) {
            if (p.first + up.first < d[up.second]) {
                d[up.second] = p.first + up.first;
                que.push(P(d[up.second], up.second));
            }
        }
    }

    sort(d.begin(), d.end());
    vector<long long> rd(d.size()), td(d.size());
    for (int i=0; i<d.size(); ++i   ) {
        rd[i] = d[i]*T;
        td[i] = d[i]*R;
    }

    long long res = 0;
    for (int i=1; i<d.size(); ++i) {
        int j = (int)distance(rd.begin(), upper_bound(rd.begin(), rd.end(), td[i]));
        res += distance(upper_bound(rd.begin(), rd.end(), td[i]), rd.end());
        if (i==j)
            --res;
    }

    return res;
}

int main() {
    int N,M,R,T;
    cin >> N >> M >> R >> T;
    vector<vector<P> > g(N);
    for (int i=0; i<M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].push_back(P(c, b));
        g[b].push_back(P(c, a));
    }

    long long ans = 0;
    for (int v=0; v<N; ++v)
        ans += calc(v, g, R, T);

    cout << ans << endl;
}