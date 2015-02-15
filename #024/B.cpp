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

int solve(int N,vector<int> &color) {
    vector<int> cnt;
    int c = 1;
    for (int i=1; i<color.size(); ++i) {
        if (color[i] == color[i-1] ) {
            ++c;
        } else {
            cnt.push_back(c);
            c = 1;
        }
    }

    if (cnt.size() == 1)
        return -1;

    if (color[0] == color[N-1])
        cnt[0] += cnt[cnt.size()-1];

    int mx = *max_element(cnt.begin(), cnt.end());
    return mx >= 3 ? (mx-1)/2 + 1 : 0;
}

int main() {
    int N;
    cin >> N;
    vector<int> color(N);
    for (int i=0; i<N; ++i)
        cin >> color[i];
    color.push_back(2);
    cout << solve(N, color) << endl;
}