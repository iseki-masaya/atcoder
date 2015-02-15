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
    vector<int> D(7), J(7);
    for (int i=0; i<7; ++i)
        cin >> D[i];
    for (int i=0; i<7; ++i)
        cin >> J[i];
    int ans = 0;
    for (int i=0; i<7; ++i)
        ans += max(D[i], J[i]);
    cout << ans << endl;
}