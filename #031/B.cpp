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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool used[15][15];

void dfs(vector<string> &m, int x, int y) {
    used[x][y] = true;
    for (int i=0; i<4; ++i) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (0 <= cx && cx < 10 && 0 <= cy && cy < 10 && !used[cx][cy] && m[cx][cy] == 'o')
            dfs(m, cx, cy);
    }
}

bool isUnified(vector<string> &m) {
    memset(used, false, sizeof(used));
    for (int x=0; x<10; ++x) {
        for (int y=0; y<10; ++y) {
            if (m[x][y] == 'o') {
                dfs(m, x, y);
                x = 11;
                y = 11;
            }
        }
    }

    for (int x=0; x<10; ++x) {
        for (int y=0; y<10; ++y) {
            if (!used[x][y] && m[x][y] == 'o') {
                return false;
            }
        }
    }

    return true;
}

string solve(vector<string> &m) {
    for (int x=0; x<10; ++x) {
        for (int y=0; y<10; ++y) {
            char prv = m[x][y];
            m[x][y] = 'o';
            if (isUnified(m))
                return "YES";
            m[x][y] = prv;
        }
    }
    return "NO";
}

int main() {
    vector<string> m;
    for (int i=0; i<10; ++i) {
        string str;
        cin >> str;
        m.push_back(str);
    }
    cout << solve(m) << endl;
}