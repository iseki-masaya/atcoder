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

long long solve(string n) {
    long long ans = 0;
    n.push_back('1');
    int s = 0;
    for (int i=0; i<n.size(); ++i) {
        if (n[i]=='2' && n[i+1]=='5') {
            s++;
            i++;
        } else {
            ans += s*(s+1)/2;
            s = 0;
        }
    }
    return ans;
}

int main() {
    string n;
    cin >> n;
    cout << solve(n) << endl;
}