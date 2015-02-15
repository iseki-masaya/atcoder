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
    long long N;
    cin >> N;

    if (N == 1) {
        cout << "Deficient" << endl;
        return 0;
    }

    long long ans = 1;
    for (long long i=2; i*i <= N; ++i) {
        if (N%i == 0) {
            long long j = N / i;
            if (i != j)
                ans += i+j;
            else
                ans += i;
        }
    }

    if (ans == N)
        cout << "Perfect" << endl;
    else if (ans < N)
        cout << "Deficient" << endl;
    else
        cout << "Abundant" << endl;
}