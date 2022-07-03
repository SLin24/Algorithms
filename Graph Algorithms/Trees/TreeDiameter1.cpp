#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
int children[200000];

int dfs(const int& index, const vector<int> *tree) {
    children[index] = 0;
    for (auto x: tree[index]) {
        children[index] = max(children[index], 1 + dfs(x, tree));
    }
    return children[index];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> adj[n];
    memset(children, -1, sizeof(children));
    for (int i = 1; i < n; i++) {
        int dest; cin >> dest;
        adj[dest-1].push_back(i);
    }
    dfs(0, adj);
    int gMax = 0;

    for (int i = 0; i < n; i++) {
        if (adj[i].size() < 2) {
            continue;
        }
        int largest = 0, sLargest = 0;
        int count = 0;
        //finding two largest lengths from children to leaf and adding together O(N) with constant factor 2
        for (auto x: adj[i]) {
            int lth = children[x];
            if (lth > largest) {
                largest = lth;
                count = 1;
            } else if (lth == largest) {
                count++;
            }
        }
        for (auto x: adj[i]) {
            int lth = children[x];
            if (lth > sLargest && (lth != largest || count >= 2)) {
                sLargest = lth;
            }
        }
        gMax = max(gMax, largest + 3 + sLargest);
    }
    cout << gMax << '\n';

    
}
