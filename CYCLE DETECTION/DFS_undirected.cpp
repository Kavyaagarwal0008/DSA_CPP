#include<bits/stdc++.h>
using namespace std;

class Graph{
public:

    int V; //vertices 
    vector<vector<int>> adj;
    Graph(int vertices){
        V=vertices;
        adj.resize(V);

    }

    void addedge(int u , int v , bool direction){

        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);

        }
    }

    //USING DFS- STACK

    bool isCycle(){
        vector<bool> visited(V,false);
        vector<int>parent(V,-1);

        for(int start=0;start<V;start++){
            if(!visited[start]){
                stack<int> st;
                visited[start]=true;
                st.push(start);

                while(!st.empty()){
                    int node = st.top();
                    st.pop();
                    for(int neighbour : adj[node]){
                        if(!visited[neighbour]){
                            visited[neighbour]=true;
                            parent[neighbour]=node;
                            st.push(neighbour);

                        }
                        else if(parent[node]!=neighbour){
                            return true; //cycle detected

                        }
                    }
                }
            }
        }
        return false;
    }

    //DFS -  Recursion
    /*
    bool dfs(int node, int parent, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (dfs(neighbour, node, visited))
                    return true;
            }
            else if (neighbour != parent) {
                return true;  // cycle detected
            }
        }
        return false;
    }
    bool isCycleDFS() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited))
                    return true;
            }
        }
        return false;
    }
    */

};
int main(){


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
        g.addedge(u, v, d);
    }

    int source;
    cout << "Enter the source vertex: " << endl;
    cin >> source;

    if (g.isCycle())
        cout << "Cycle Detected in Undirected Graph" << endl;
    else
        cout << "No Cycle in Undirected Graph" << endl;

    return 0;
}