#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

//2 Way BFS ALGORITHM FOR BIDERICTIONAL TREE DIAMETER
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> adj[n];
    if (n == 1) {
        cout << "0" << '\n';
    } else {
        for (int i = 0; i < n - 1; i++) {
            int src, dest; cin >> src >> dest;
            adj[src - 1].push_back(dest - 1);
            adj[dest - 1].push_back(src - 1);
        }
        

        queue<int> q;
        int lastElem = -1;
        q.push(0);
        bool visited[n]{};
        while (!q.empty()) {
            visited[q.front()] = true; //usually don't want to place visited here, but in the case of BFS, it is fine. Other algorithms like dijkstra's may run into problems
            if (q.size() == 1 && adj[q.front()].size() == 1 && q.front() != 0) {
                lastElem = q.front();
                q.pop();
                break;
            }
            int node = q.front();
            q.pop();

            for (auto x: adj[node]) {
                if (!visited[x]) q.push(x);
            }
        }
        queue<pair<int, int>> q2;
        memset(visited, false, sizeof(visited));
        
        q2.push(make_pair(lastElem, 1));
        int dist = -1;

        while (!q2.empty()) {
            visited[q2.front().first] = true;
            if (q2.size() == 1 && adj[q2.front().first].size() == 1 && q2.front().first != lastElem) {
                dist = q2.front().second - 1; //no need to add the last element because distance is # of nodes - 1
                q2.pop();
                break;
            } 
            int node = q2.front().first;
            int d = q2.front().second;
            q2.pop();
            for (auto x: adj[node]) {
                if (!visited[x]) q2.push(make_pair(x, d + 1));
            }
        }
        cout << dist << '\n';
    }

    
}
