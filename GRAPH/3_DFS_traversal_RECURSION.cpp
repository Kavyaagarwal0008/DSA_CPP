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


    void DFS(int source){
        vector<bool> visited(V,false);

        stack<int> st;

        st.push(source);

        cout<<" DFS- ";
        while(!st.empty()){
            int node=st.top();
            st.pop();

            if(!visited[node]){
                visited[node]=true;
                cout<<node<<" ";

                //push neighbours in reverse order
                //to maintain the same order as of recursion 

                for(int i=adj[node].size()-1 ; i>=0;i--){
                    int neighbour=adj[node][i];
                    if(!visited[neighbour]){
                        st.push(neighbour);
        
                    }
                }
            }
        }
        cout<<endl;
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

    g.DFS(source);

    return 0;
}
