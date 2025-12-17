#include<bits/stdc++.h>
using namespace std;

class Graph{
public:

    int V;
    vector<vector<int>> adj;

    Graph(int vertices){
        V=vertices;
        adj.resize(V);
    }

    void addedge(int u, int v){
        adj[u].push_back(v);

    }

    void DFS(int node , vector<bool>&visited){
        visited[node]=true;
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                DFS(neighbour,visited);

            }
        }
    }
    int mother(){
        vector<bool> visited(V,false);
        int lastvertex=-1;

        //find the last vertex 
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(i,visited);
                lastvertex=i;
            }
        }
        //vertex small than lastvertex
        for(int i=0;i<=lastvertex;i++){
            //verify
            fill(visited.begin(),visited.end(),false);
            DFS(lastvertex,visited);

            bool ismother=true;
            for(bool a : visited ){
                if(!a){

                    ismother=false;
                    break;
                }
            }
            if(ismother){
                return i; //smallest
            }
        }
        return -1;
    }
     
};

int main(){

    int V,E;
    cout<<"Enter the number of vertices and edges  "<<endl;

    cin>>V>>E;

    Graph g(V);
    cout<<"Enter the edges ( u v ) "<<endl;
    for(int i=0;i<E;i++){
        int u, v;
        cin>>u>>v;
        g.addedge(u,v);

    }
    cout<<endl;
    cout<<g.mother();
    cout<<endl;
    return 0;
}