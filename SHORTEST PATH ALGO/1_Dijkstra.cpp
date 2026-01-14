#include<bits/stdc++.h>
using namespace std; 

class Graph{
public:

    int v;
    vector<vector<pair<int, int>>> adj;
    Graph(int vertices){
        v=vertices;
        adj.resize(v);
    }

    void addedge(int u, int v, int wt , bool directed=false){
        adj[u].push_back({v,wt});
        if(directed==false){
            adj[v].push_back({u,wt});
        }

    }
    void dijkstra(int src){
        priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<>>pq;
        vector<int> dist(v,INT_MAX);
        dist[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            int currDist=pq.top().first;
            int node=pq.top().second;

            pq.pop();

            if(currDist> dist[node]){
                continue;
            }

            for(auto &edge : adj[node]){
                int neigh=edge.first;
                int weight=edge.second;

                if(dist[node]+weight < dist[neigh]){
                    dist[neigh]=dist[node]+weight;

                    pq.push({dist[neigh],neigh});
                }

            }
        }
        cout<<"Shortes distance from source - "<< src << endl;
        for(int i=0;i<v;i++){
            cout<<"Node "<<i<< "=" << dist[i]<<endl;
        }
    }
};
int main(){
    Graph g(5);

    g.addedge(0,1,2);
    g.addedge(0, 3, 6);
    g.addedge(1, 2, 3);
    g.addedge(1, 3, 8);
    g.addedge(1, 4, 5);
    g.addedge(2, 4, 7);
    g.addedge(3, 4, 9);

    g.dijkstra(0);
    

    return 0;
}