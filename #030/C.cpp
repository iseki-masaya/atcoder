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

vector<char> h;
bool conn[305][305];
bool nconn[305][305];
typedef pair<int, string> P;
vector<P> vp;
vector<P> svp;
vector<bool> usedsc;
string ans;
int K;

void tsort(int v) {
    usedsc[v] = true;
    for (int u=0; u<vp.size(); ++u) {
        if (!usedsc[u] && nconn[v][u]) {
            tsort(u);
        }
    }
    svp.push_back(vp[v]);
}

string solve(int n) {
    for (int l=0; l<n; ++l) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                conn[i][j] |= conn[i][l] & conn[l][j];
            }
        }
    }

    vp.clear();
    vector<bool> usedv(n, false);

    for (int i=0; i<n; ++i) {
        if (usedv[i])
            continue;
        usedv[i] = true;
        string str = "";
        str += h[i];
        for (int j=0; j<n; ++j) {
            if (!usedv[j] && i!=j && conn[i][j] && conn[j][i]) {
                str += h[j];
                usedv[j] = true;
            }
        }
        sort(str.begin(), str.end());
        vp.push_back(P(i, str));
    }

    memset(nconn, false, sizeof(nconn));
    for (int i=0; i<vp.size(); ++i) {
        for (int j=0; j<vp.size(); ++j) {
            if (i == j)
                continue;
            int a = vp[i].first;
            int b = vp[j].first;
            if (conn[a][b])
                nconn[i][j] = true;
        }
    }

    usedsc.clear(); usedsc.resize(vp.size(), false);
    for (int i=0; i<vp.size(); ++i) {
        if (!usedsc[i])
            tsort(i);
    }

    for (int i=0; i<vp.size(); ++i)
        vp[i] = svp[vp.size()-1-i];

    memset(nconn, false, sizeof(nconn));
    for (int i=0; i<vp.size(); ++i) {
        for (int j=0; j<vp.size(); ++j) {
            if (i == j)
                continue;
            int a = vp[i].first;
            int b = vp[j].first;
            if (conn[a][b])
                nconn[i][j] = true;
        }
    }

    string dp[305][305];
    for (int i=0; i<vp.size(); ++i) {
        string from[303];
        for (int j=0; j<i; ++j) if(i!=j && nconn[j][i]) {
            for (int k=0; k<K; ++k) {
                if (dp[j][k].size() == k && (from[k].size() != k || dp[j][k] < from[k])) {
                    from[k] = dp[j][k];
                }
            }
        }

        for (int k=0; k<K; ++k)
            dp[i][k] = from[k];

        string s = vp[i].second;
        for (int len=1; len<=s.size(); ++len) {
            string add = s.substr(0,len);
            for (int k=0; k+len<K; ++k) {
                if (from[k].size() == k && (dp[i][k+len].size() != k+len || from[k]+add < dp[i][k+len])) {
                    dp[i][k+len] = from[k] + add;
                }
            }
        }
    }

    string ans(K-1, '~');
    for (int i=0; i<n; ++i) {
        if (dp[i][K-1].size() == K-1) {
            ans = min(ans, dp[i][K-1]);
        }
    }
    return ans;
}

int main() {
    int n,m;
    cin >> n >> m >> K;
    ++K;
    memset(conn, false, sizeof(conn));
    h.clear(); h.resize(n);

    for (int i=0; i<n; ++i)
        cin >> h[i];

    for (int i=0; i<m; ++i) {
        int a,b;
        cin >> a >> b;
        --a, --b;
        conn[a][b] = true;
    }
    string ans = solve(n);
    if (ans[0] == '~')
        cout << -1 << endl;
    else
        cout << ans << endl;
}