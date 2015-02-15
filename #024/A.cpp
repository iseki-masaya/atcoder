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

int main() {
    int L,R;
    cin >> L >> R;
    vector<int> l(45,0),r(45,0);
    for (int i=0; i<L; ++i) {
        int ls;
        cin >> ls;
        l[ls]++;
    }
    for (int i=0; i<R; ++i) {
        int rs;
        cin >> rs;
        r[rs]++;
    }

    int ans = 0;
    for (int i=10; i<=40; ++i)
        ans += min(l[i], r[i]);

    cout << ans << endl;
}