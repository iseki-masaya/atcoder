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

int conv(char ch) {
    return ch - 'a';
}

string solve(int N, int K, string &S) {
    set<vector<int> > s;
    queue<vector<int> > que;
    vector<int> d(27,0);
    for (int i=0; i<K; ++i)
        d[conv(S[i])]++;
    que.push(d);
    for (int i=K; i<N; ++i) {
        if (que.size() == K) {
            s.insert(que.front());
            que.pop();
        }
        d[conv(S[i-K])]--;
        d[conv(S[i])]++;
        if (s.count(d))
            return "YES";
        que.push(d);
    }
    return "NO";
}

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    cout << solve(N, K, S) << endl;
}