// Kahn Algorithm 
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

    void addEdge(int u , int v){
        adj[u].push_back(v);

    }

    bool iscycle(){
        vector<int> indegree(V,0);

        for(int i=0;i<V;i++){
            for(int v : adj[i]){

                indegree[v]++;
            }
        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);

                }
            }
        }
        return (count != V); //cycle if topo sort is incomplete 

    }

};

int main() {
    int V, E;
    cout<<"Enter the number of vertices and edges -"<<endl;
    cin >> V >> E;

    Graph g(V);
    cout<<"Enter edges (u v)"<<endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.iscycle())
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}