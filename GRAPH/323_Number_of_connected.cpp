#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for(int neighbour : adj[node]) {
        if(!visited[neighbour]) {
            dfs(neighbour, adj, visited);
        }
    }
}

int countComponents(int V, vector<vector<int>>& edges) {

    vector<vector<int>> adj(V);

    for(auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(V, false);
    int cnt = 0;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            cnt++;
            dfs(i, adj, visited);
        }
    }
    return cnt;
}

int main() {

    int V = 5;
    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {3,4}
    };

    cout << countComponents(V, edges) << endl;
    return 0;
}
