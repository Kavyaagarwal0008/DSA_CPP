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
    
    void addedge(int u, int v){
        //no direction as it is directed graph 
        adj[u].push_back(v);
        
    }
    bool isCycle(){
        vector<bool>visited(V,false);
        vector<int> recstack(V,false); //recursion stack

        for(int start=0; start<V;start++){

            if(!visited[start]){
                stack<pair<int,int>> st;
                st.push({start,0});


                while(!st.empty()){
                    // auto &[node, idx]=st.top();
                    int &node=st.top().first;
                    int &idx=st.top().second;

                    if(!visited[node]){
                        visited[node]=true;
                        recstack[node]=true;

                    }

                    if (idx < adj[node].size()) {
                        int neighbour = adj[node][idx];
                        idx++;

                        if (!visited[neighbour]) {
                            st.push({neighbour, 0});
                        }
                        else if (recstack[neighbour]) {
                            return true; // cycle detected
                        }
                    }

                    else{
                        recstack[node]=false;
                        st.pop();
                    }
                }
            }
        }
        return false;
    }
};

int main(){


    int V, E;
    cout << "Enter number of vertices and edges for graph: " << endl;
    cin >> V >> E;
    Graph g(V);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v);
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