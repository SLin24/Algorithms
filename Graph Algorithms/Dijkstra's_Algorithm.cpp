#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;


//note that in this problem (CSES), the paths were unidirectional
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    //pair is weight, vertex
    vector<pair<ll, ll>> adj[n];
    vector<ll> dist(n, 1e18);
    for (int i = 0; i < m; i++) {
        ll src, dest, weight; cin >> src >> dest >> weight;
        src--; dest--;
        adj[src].push_back(make_pair(weight, dest));
    }
    //note that priority queue sorts items from greatest to least, so greater<pair<ll, ll>> reverses that ordering
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push(make_pair(0, 0));
    dist[0] = 0;
    bool visited[n]{};
    while (!pq.empty()) {
        ll vertex = pq.top().second;
        pq.pop();
        if (visited[vertex]) {
            continue;
        }
        visited[vertex] = true;
        /*For all neighbors of vertex, check if there is a connection that reduces an edge length. 
        The reason we can mark vertex as visited, even if we don't know if there might be another path connected to it, is because we know that it is the shortest in the queue.
        Unless there is a negative distance, the distance from the start node to vertex will always be the shortest. 
        This is the reason why Dijkstra's Algorithm fails in the case of negative edge lengths.
        */
        for (auto x: adj[vertex]) {
            ll dest = x.second;
            ll w = x.first;
            if (dist[dest] > dist[vertex] + w) {
                dist[dest] = dist[vertex] + w;
                pq.push(make_pair(dist[dest], dest));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << '\n';


}
