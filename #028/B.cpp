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
    int N;
    vector<int> bit;

public:
    BIT(int n): N(n) {
        bit.clear();
        bit.resize(n+5, 0);
    }

    void add(int n) {
        while (n <= N) {
            bit[n]++;
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

    int getRank(int k) {
        int ub = N+1, lb = 0;
        while (ub - lb > 1) {
            int md = (ub + lb) / 2;
            int c = cnt(md);
            if (c < k)
                lb = md;
            else
                ub = md;
        }
        return ub;
    }
};



int main() {
    int N,K;
    cin >> N >> K;
    vector<int> X(N);
    map<int, int> rank;
    for (int i=0; i<N; ++i) {
        cin >> X[i];
        rank[X[i]] = i+1;
    }

    unique_ptr<BIT> b(new BIT(N+1));
    for (int i=0; i<K-1; ++i)
        b->add(X[i]);
    for (int i=K-1; i<N; ++i) {
        b->add(X[i]);
        cout << rank[b->getRank(K)] << endl;
    }
    return 0;
}