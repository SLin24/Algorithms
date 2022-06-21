#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
//Bellman Ford's Algorithm except with finding maximum path length and detecting positive cycles. (CSES High Score)
struct Edge {
    ll a, b, x;
};
int n;
bool visited[2500];
bool bVisited[2500];
void dfs(const int& index, const vector<int> *adj) {
    for (int x: adj[index]) {
        if (!visited[x]) {
            visited[x] = true;
            dfs(x, adj);
        }
    }
}
 
void bDfs(const int& index, const vector<int> *adj) {
    for (int x: adj[index]) {
        if (!bVisited[x]) {
            bVisited[x] = true;
            bDfs(x, adj);
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
    vector<int> adj2[n];
    for (int i = 0; i < m; i++) {
        ll a, b, x; cin >> a >> b >> x;
        a--, b--;
        adj[a].push_back(b);
        adj2[b].push_back(a);
        edges[i] = {a, b, x};
    }
    dfs(0, adj);
    bDfs(n - 1, adj2);
    dist[0] = 0;
    bool ok = true;
    //Iterate over all m edges n times. Time complexity will be O(N * M)
    for (int i = 0; i < n; i++) {
        for (auto e: edges) {
            dist[e.b] = max(dist[e.b], (dist[e.a] + e.x));
        }
    }
    ll distCheck[n];
    for (int i = 0; i < n; i++) {
        distCheck[i] = -1e18;
    }
    for (auto e: edges) {
        distCheck[e.b] = max(distCheck[e.b], max(dist[e.b], dist[e.a] + e.x));
    }
    //checks if the "positive" cycle is within the path between the start node and the finish node
    for (int i = 0; i < n; i++) {
        if (distCheck[i] > dist[i] && visited[i] && bVisited[i]) {
            ok = false;
        }
    }
    cout << (ok?dist[n - 1]:-1) << '\n';
}
