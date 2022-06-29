#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

vector<int> pow2;
int maxTable[19][250007];
int minTable[19][250007];
int binSearch(int x) {
    return 32 - __builtin_clz(x) - 1;
}

int queryMin(const int& left, const int& right) {
    int dist = (right - left + 1);
    int length = binSearch(dist);
    int skip = pow2[length];
    int mn = min(minTable[length][left], minTable[length][right - skip + 1]);
    return mn;
}
int queryMax(const int& left, const int& right) {
    int dist = (right - left + 1);
    int length = binSearch(dist);
    int skip = pow2[length];

    int mx = max(maxTable[length][left], maxTable[length][right - skip + 1]);
    return mx;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    int cur = 1;
    for (int i = 0; i < 30; i++) {
        pow2.emplace_back(cur);
        cur *= 2;
    }
    int n; cin >> n;

    int sz = binSearch(n);

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        minTable[0][i] = num;
        maxTable[0][i] = num;
    }
    for (int i = 1; i <= sz; i++) {
        int skip = pow2[i];
        for (int j = 0; j <= n - skip; j++) {
            minTable[i][j] = min(minTable[i - 1][j], minTable[i - 1][j + skip / 2]);
            maxTable[i][j] = max(maxTable[i - 1][j], maxTable[i - 1][j + skip / 2]);
        }
    }   

    
}
