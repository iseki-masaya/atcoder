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
    int Na, Nb;
    cin >> Na >> Nb;
    set<int> a, b;
    for (int i=0; i<Na; ++i) {
        int c;
        cin >> c;
        a.insert(c);
    }
    for (int i=0; i<Nb; ++i) {
        int c;
        cin >> c;
        b.insert(c);
    }

    int prod = 0;
    for (int v: a) {
        if (b.find(v) != b.end()) {
            ++prod;
        }
    }
    int sum = (int)a.size() + (int)b.size() - prod;
    double ans = (double)prod / sum;
    printf("%.10f\n", ans);
}