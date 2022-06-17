#include <bits/stdc++.h>
#include <iostream>
#pragma GCC target("popcnt")
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m, q; cin >> n >> m >> q;


    ll grid[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 1e18;
        }
        grid[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        grid[a][b] = min(grid[a][b], c);
        grid[b][a] = min(grid[b][a], c);
    }

    //Important to note that i is the node connecting the two paths. Essentially the path will be from j -> i -> k where i is the middle node
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (grid[j][k] > ((ll)grid[j][i] + (ll)grid[i][k]) && grid[j][i] != 1e18 && grid[i][k] != 1e18) {
                    grid[j][k] = (ll)grid[j][i] + (ll)grid[i][k];
                }
            }
        }
    }
    

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (grid[a][b] == 1e18) {
            cout << "-1" << '\n';
        } else {
            cout << grid[a][b] << '\n';
        }
    }
 
}
