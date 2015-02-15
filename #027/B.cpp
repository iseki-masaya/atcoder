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

bool used[20];

string s1, s2;

void dfs(int idx) {
    used[idx] = true;
    for (int i=0; i<s1.size(); ++i) {
        if (!used[i] &&
                (s1[i] == s1[idx] || s1[i] == s2[idx] ||
                 s2[i] == s1[idx] || s2[i] == s2[idx]) ) {
                    dfs(i);
        }
    }
}

int main() {
    int N;
    cin >> N >> s1 >> s2;
    memset(used, false, sizeof(used));
    for (int i=0; i<N; ++i) {
        if ( 'A' <= s1[i] && s1[i] <= 'Z' && 'A' <= s2[i] && s2[i] <= 'Z' )
            continue;
        dfs(i);
    }

    long long ans = 1;
    for (int i=0; i<N; ++i) {
        if (used[i])
            continue;
        ans *= i==0 ? 9LL : 10LL;
        dfs(i);
    }

    cout << ans << endl;
}