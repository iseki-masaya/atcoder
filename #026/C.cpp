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

class SegmentTree {
    vector<long long> dat;
    int N;
public:

    SegmentTree(int n) {
        N = 1;
        while (N < n)
            N <<= 1;
        dat.clear();
        dat.resize(2*N, LINF);
    }

    void update(int idx, long long v) {
        idx += N - 1;
        dat[idx] = min(dat[idx], v);
        while (idx > 0) {
            idx = (idx-1)/2;
            dat[idx] = min(dat[2*idx+1], dat[2*idx+2]);
        }
    }

    long long query(int a, int b, int idx, int l = 0, int r = -1) {
        if (r == -1)
            r = N;
        if (r <= a || b <= l)
            return LINF;
        else if (a <= l && r <= b)
            return dat[idx];
        int m = (l+r)/2;
        long long lhs = query(a, b, 2*idx+1, l, m);
        long long rhs = query(a, b, 2*idx+2, m, r);
        return min(lhs, rhs);
    }
};

typedef tuple<int, int, int> P;

int main() {
    int N, L;
    cin >> N >> L;
    vector<P> p(N);
    for (int i=0; i<N; ++i)
        cin >> get<0>(p[i]) >> get<1>(p[i]) >> get<2>(p[i]);
    sort(p.begin(), p.end());
    vector<long long> dp(L+2, LINF);
    dp[0] = 0;

    unique_ptr<SegmentTree> st(new SegmentTree(L+1));
    st->update(0, 0);
    for (int i=0; i<N; ++i) {
        int l = get<0>(p[i]);
        int r = get<1>(p[i]);
        long long c = get<2>(p[i]);
        long long mn = st->query(l, r, 0);
        dp[r] = min(dp[r], mn+c);
        st->update(r, mn+c);
    }

    cout << dp[L] << endl;
}