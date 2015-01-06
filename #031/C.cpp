#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <thread>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class BIT {
    vector<int> bit;
    int N;

public:
    BIT(int n) : N(n+1) {
        bit.clear();
        bit.resize(N, 0);
    }

    void add(int n) {
        while (n < N) {
            bit[n]++;
            n += n&-n;
        }
    }

    void del(int n) {
        while (n < N) {
            bit[n]--;
            n += n&-n;
        }
    }

    int left(int n) {
        int res = 0;
        while (n > 0) {
            res += bit[n];
            n -= n&-n;
        }
        return res;
    }

    int right(int n) {
        return left(N-1) - left(n);
    }
};

long long solve(vector<int> &v) {
    map<int, int> m;
    int N = (int)v.size();
    for (int i=0; i<N; ++i)
        m[v[i]] = i+1;
    BIT b(N);
    for (int i=1; i<=N; ++i)
        b.add(i);

    long long ans = 0;
    for (int i=1; i<=N; ++i) {
        int idx = m[i];
        int cnt = min(b.left(idx-1), b.right(idx));
        ans += cnt;
        b.del(idx);
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i=0; i<N; ++i)
        cin >> v[i];
    cout << solve(v) << endl;
}