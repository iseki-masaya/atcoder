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

string solve(string S) {
    int N = (int)S.size();
    int left = 0, right = N-1;
    while (left < right) {
        if (S[left] != S[right])
            return "NO";
        ++left;
        --right;
    }
    return "YES";
}

int main() {
    string str;
    cin >> str;
    cout << solve(str) << endl;
}