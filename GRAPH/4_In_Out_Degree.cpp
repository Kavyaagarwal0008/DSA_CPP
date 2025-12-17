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

    void addEdge(int u, int v) {
        adj[u].push_back(v);   // directed edge
    }

    void countInOutDegree() {
        vector<int> indegree(V, 0);
        vector<int> outdegree(V, 0);

        for (int u = 0; u < V; u++) {
            outdegree[u] = adj[u].size();   // count outgoing edges

            for (int v : adj[u]) {
                indegree[v]++;              // count incoming edges
            }
        }

        cout << "Vertex  Indegree  Outdegree\n";
        for (int i = 0; i < V; i++) {
            cout << i << "\t" << indegree[i]<< "\t   " << outdegree[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: " << endl;
    cin >> V >> E;

    Graph g(V);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.countInOutDegree();

    return 0;
}



/*

FOR UNDIRECTED GRAPH (IMPORTANT NOTE)

In undirected graph: Indegree = Outdegree = Degree
Each edge adds 1 degree to both vertices
degree[v] = adj[v].size()

*/
