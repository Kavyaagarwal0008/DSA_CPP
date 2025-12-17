// Given a Directed Acyclic Graph having V vertices and E edges, find any Topological Sorted ordering of the graph.

// Topological Sorted order: It is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.

#include<bits/stdc++.h>
using namespace std;

vector<int> toposort(vector<vector<int>>&adj){

    int n=adj.size();
    vector<int> indegree(n,0);
    queue<int> q;
    vector<int> list;

    //compute indegree
    for(int i=0;i<n;i++){
        for(int next : adj[i]){
            indegree[next]++;
        }
    }
    // add edges with 0 indegree into queue
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);

        }
    }

    //Kahn Algo
    while(!q.empty()){
        int top=q.front();
        q.pop();

        list.push_back(top);
        for(int next : adj[top]){
            indegree[next]--;
            if(indegree[next]==0){
                q.push(next);
            }
        }
    }
    return list;
}

void addEdge(vector<vector<int>> &adj, int u , int v){
    adj[u].push_back(v);
}

int main(){
    int n=6;
    vector<vector<int>> adj(n);
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 1);
    addEdge(adj, 5, 2);

    vector<int> res = toposort(adj);
    for (int vertex : res)
        cout << vertex << " ";
    cout << endl;

    return 0;

}