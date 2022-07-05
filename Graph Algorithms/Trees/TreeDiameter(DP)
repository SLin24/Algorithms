#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
int dp1[200000]{}; //stores maximum of singular paths branching from a node
int dp2[200000]{}; //stores the maximum path going through a node (where node is the highest point in the graph)
int diam = -1;
void dfs(const int& i, const int& p, const vector<int> *adj) {
    dp1[i] = 1;
    int mx = -1, secMx = -1;
    for (auto x: adj[i]) {
        if (x == p) continue;
        dfs(x, i, adj);

        if (dp1[x] >= mx) {
            secMx = mx;
            mx = dp1[x];
        } else if (dp1[x] > secMx) {
            secMx = dp1[x];
        }
    }
    if (mx != -1) {
        dp1[i] += mx;
    }
    if (secMx != -1) {
        dp2[i] = 1 + mx + secMx;
    }
    diam = max(diam, max(dp1[i], dp2[i]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> adj[n];
    if (n == 1) {
        cout << "0" << '\n';
    } else {
        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, 0, adj);

        cout << diam - 1 << '\n';
        
    }

    
}
