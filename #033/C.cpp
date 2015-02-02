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

class BIT {
    vector<int> bit;
    int N;

public:
    BIT(int n) {
        N = n+5;
        bit.clear();
        bit.resize(N, 0);
    }

    void add(int n) {
        while (N > n) {
            bit[n]++;
            n += n&-n;
        }
    }

    void del(int n) {
        while (N > n) {
            bit[n]--;
            n += n&-n;
        }
    }

    int cnt(int n) {
        int res = 0;
        while (n > 0) {
            res += bit[n];
            n -= n&-n;
        }
        return res;
    }

    int delX(int n) {
        int lb = 0, ub = N+1;
        while (ub - lb > 1) {
            int md = (lb + ub) / 2;
            if (cnt(md) < n)
                lb = md;
            else
                ub = md;
        }
        del(ub);
        return ub;
    }
};

int main() {
    int Q;
    cin >> Q;
    unique_ptr<BIT> bit(new BIT(200005));
    for (int i=0; i<Q; ++i) {
        int T,X;
        cin >> T >> X;
        if (T == 1) {
            bit->add(X);
        } else {
            cout << bit->delX(X) << endl;
        }
    }
    return 0;
}