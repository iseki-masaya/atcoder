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

vector<vector<P> > dp;
vector<vector<int> > C;

// even even

int solve(int H, int W) {
    for (int h=1; h<H; ++h) {
        for (int w=1; w<W; ++w) {
            bool isWhite = (h+w)&1;
            int white = dp[h-1][w].first + dp[h][w-1].first - dp[h-1][w-1].first + (isWhite ? C[h][w] : 0);
            int black = dp[h-1][w].second + dp[h][w-1].second - dp[h-1][w-1].second + (isWhite ? 0 : C[h][w]);
            dp[h][w] = P(white, black);
        }
    }

    int ans = 0;
    for (int uh=1; uh<H; ++uh) {
        for (int uw=1; uw<W; ++uw) {
            for (int lh=1; lh<=uh; ++lh) {
                for (int lw=1; lw<=uw; ++lw) {
                    int white = dp[uh][uw].first - dp[uh][lw-1].first - dp[lh-1][uw].first + dp[lh-1][lw-1].first;
                    int black = dp[uh][uw].second - dp[uh][lw-1].second - dp[lh-1][uw].second + dp[lh-1][lw-1].second;
                    if (white == black)
                        ans = max(ans, (uh-lh+1)*(uw-lw+1) );
                }
            }
        }
    }

    return ans;
}

int main() {
    int H, W;
    cin >> H >> W;
    ++H, ++W;
    dp.clear();
    dp.resize(H, vector<P>(W, P(0,0)));
    C.clear();
    C.resize(H, vector<int>(W, 0));
    for (int h=1; h<H; ++h) {
        for (int w=1; w<W; ++w) {
            cin >> C[h][w];
        }
    }
    cout << solve(H, W) << endl;
}