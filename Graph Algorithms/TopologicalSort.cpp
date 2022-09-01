#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> adj[n];
    int indegree[n]{};
    for (int i = 0; i < m; i++) {
        int s, d; cin >> s >> d; s--; d--;
        adj[s].push_back(d);
        indegree[d]++;
    } 
    queue<int> q; 
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> order;

    while (order.size() < n) {
        int tp = q.front();
        q.pop();
        order.push_back(tp);
        for (int x: adj[tp]) {
            indegree[x]--;
            if (indegree[x] == 0) {
                q.push(x);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << order[i] << " ";
    }
    cout << '\n';


}