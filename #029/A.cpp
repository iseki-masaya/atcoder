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

int calc(vector<int> &t, vector<int> &p) {
    int a = 0, b = 0;
    for (int i=0; i<p.size(); ++i) {
        if (a <= b)
            a += t[p[i]];
        else
            b += t[p[i]];
    }
    return max(a, b);
}

int main() {
    int n;
    cin >> n;
    vector<int> t(n), p(n);
    for (int i=0; i<n; ++i) {
        cin >> t[i];
        p[i] = i;
    }
    int ans = INF;
    do {
        ans = min(ans, calc(t, p));
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}