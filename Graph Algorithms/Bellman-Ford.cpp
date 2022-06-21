#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

struct Edge {
    ll a, b, x;
};
int n;
bool pass = false;
bool visited[2500];
//CSES High Score
//Bellman Ford's Algorithm, except used to find maximum distance with "positive" cycles instead of negative cycles (O(N*M) algorithm)
//only reason there is a dfs here is to check if the "positive" cycle is connected to both the starting point and the ending point. 
void dfs(const int& index, const int& target, const vector<int> *adj) {
    if (index == target || pass) {
        pass = true;
        return;
    }
    for (int x: adj[index]) {
        if (!visited[x]) {
            visited[x] = true;
            dfs(x, target, adj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m; cin >> n >> m;

    ll dist[n];

    for (int i = 0; i < n; i++) {
        dist[i] = -1e18;
    }
    Edge edges[m];
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        ll a, b, x; cin >> a >> b >> x;
        a--, b--;
        adj[a].push_back(b);
        edges[i] = {a, b, x};
    }
    //initialize starting node distance to 0, and iterate through all edges
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto e: edges) {
            dist[e.b] = max(dist[e.b], (dist[e.a] + e.x));
        }
    }
    ll distCheck[n]{};
    for (int i = 0; i < n; i++) {
        distCheck[i] = -1e18;
    }
    for (auto e: edges) {
        distCheck[e.b] = max(distCheck[e.b], max(dist[e.b], (dist[e.a] + e.x)));
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (distCheck[i] > dist[i]) {
            pass = false;
            //wastes a lot of time with memset (There's a more efficient way to check if a positive cycle is connected to the start and end nodes)
            memset(visited, false, sizeof(visited));
            dfs(i, n - 1, adj);
            if (!pass) continue;
            pass = false;
            memset(visited, false, sizeof(visited));
            dfs(0, i, adj);
            if (pass) {
                ok = false;
                break;
            }
        }
    }
    cout << (ok?dist[n - 1]:-1) << '\n';
}
