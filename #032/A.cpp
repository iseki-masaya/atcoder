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

bool isPrime(int n) {
    if (n == 1)
        return false;
    for (int i=2; i*i<=n; ++i) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << (isPrime(n*(n+1)/2) ? "WANWAN" : "BOWWOW") << endl;
}