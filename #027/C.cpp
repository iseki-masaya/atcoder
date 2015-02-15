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

int dp[610][305];

int main() {
    int X,Y,N;
    cin >> X >> Y >> N;
    vector<int> t(N),h(N);
    for (int i=0; i<N; ++i)
        cin >> t[i] >> h[i];

    memset(dp, -1, sizeof(dp));
    dp[X+Y][X] = 0;
    int ans = 0;
    for (int i=0; i<N; ++i) {
        for (int s=0; s<X+Y; ++s) {
            for (int x=0; x<X; ++x) {
                int T = t[i];
                int H = h[i];
                if (s + T > X+Y || dp[s+T][x+1] == -1)
                    continue;
                dp[s][x] = max(dp[s][x], dp[s+T][x+1] + H);
                ans = max(ans, dp[s][x]);
            }
        }
    }
    cout << ans << endl;
}