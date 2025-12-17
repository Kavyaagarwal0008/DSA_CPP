#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;                    
    vector<vector<int>> adj;       

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);

        if (direction == 0) {      // 0 = undirected
            adj[v].push_back(u);
        }
    }

    bool dfs(int node,int col, vector<int>&color){
        color[node]=col;

        for(int neighbour : adj[node]){
            if(color[neighbour]==-1){
                if(!dfs(neighbour,1-col,color)){
                    return false;
                }
            }

            else if(color[neighbour]==col){
                return false;
            }
        }
        return true;
    }
    bool DFS_Coloring() {
        vector<int> color(V, -1);   // -1 = uncolored, 0 and 1 are colors

        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color)){
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

    int V, E;
    cout << "Enter number of vertices and edges for graph: " << endl;
    cin >> V >> E;

    int d;
    cout << "Enter 0 for undirected graph else 1: " << endl;
    cin >> d;

    Graph g(V);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, d);
    }

    if (g.DFS_Coloring())
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is NOT Bipartite" << endl;

    return 0;
}
