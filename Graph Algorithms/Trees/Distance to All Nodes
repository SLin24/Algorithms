#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
int dp1[200000]{};
int dp2[200000]{};
int c[200000];
//PROBLEM IS CSES TREE DISTANCE 1
void dfs(const int& i, const int& p, const vector<int> *adj) {
    //counts # of nodes in longest and second longest paths
    dp1[i] = 1, dp2[i] = 1;
    int mx = -1, secMx = -1; //longest distance to a leaf node and second longest distance to a leaf node. (Only paths with completely different elements are considered to be different paths)
    for (auto x: adj[i]) {
        if (x == p) continue;
        dfs(x, i, adj);
        if (dp1[x] >= mx) {
            c[i] = x;
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
        dp2[i] += secMx;
    }
}

void dfs2(const int& i, const int& p, const vector<int> *adj) {
    for (auto x: adj[i]) {
        if (x == p) continue;

        if (c[i] == x) {
            //if the longest path goes through the current node, compare the second longest path going through the parent node and the path going from the current node to a leaf
            if (dp1[x] < dp2[i] + 1) {
                c[x] = i;
                dp2[x] = dp1[x];
                dp1[x] = dp2[i] + 1;
            } else {
                dp2[x] = max(dp2[x], dp2[i] + 1);
            }
        } else {
            //if the longest path does not go through the current node, it means that the longest path from the current node is through the parent
            dp2[x] = dp1[x];
            dp1[x] = dp1[i] + 1;
            c[x] = i;
        }

        dfs2(x, i, adj);
    }
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
        dfs(0, -1, adj);
        dfs2(0, -1, adj);

        for (int i = 0; i < n; i++) {
            cout << dp1[i] - 1 << " ";
        }
        cout << '\n';
        
    }

    
}
