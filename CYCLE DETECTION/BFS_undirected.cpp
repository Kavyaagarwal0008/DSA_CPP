#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;                         // number of vertices
    vector<vector<int>> adj;       // adjacency list
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

    //BFS based cycle detection
    bool iscycle(){
        vector<bool> visited(V,false);
        vector<int> parent(V,-1);

        for(int start=0; start<V ; start++){
            if(!visited[start]){
                queue<int>q;

                visited[start]=true;
                q.push(start);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for (int neighbour : adj[node]) {
                        if (!visited[neighbour]) {
                            visited[neighbour] = true;
                            parent[neighbour] = node;
                            q.push(neighbour);
                        }
                        else if (parent[node] != neighbour) {
                            return true; // cycle detected
                        }
                    }
                }
            }
        }
    
        return false;
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

    int source;
    cout << "Enter the source vertex: " << endl;
    cin >> source;

    if (g.iscycle())
        cout << "Cycle Detected in Undirected Graph" << endl;
    else
        cout << "No Cycle in Undirected Graph" << endl;

    return 0;
}
