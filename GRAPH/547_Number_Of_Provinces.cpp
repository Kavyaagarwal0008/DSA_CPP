#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int city , vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[city]=true;

        for(int next=0;next<isConnected.size();next++){
            if(isConnected[city][next]==1 && visited[next]==false){
                dfs(next , isConnected , visited);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<bool> visited(V,false);
        int provinces=0;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                provinces++;
                dfs(i,isConnected,visited);
            }
        }
        return provinces;
    }
};

int main(){
    vector<vector<int>> isConnected= {{1,1,0},{1,1,0},{0,0,1}};

    Solution s;

    cout<<s.findCircleNum(isConnected)<<endl;

}



/*
Matrix -> Adj List ->DFS


class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        // Step 1: Convert matrix to adjacency list
        vector<vector<int>> adj(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        // Step 2: Count connected components using DFS
        vector<bool> visited(V, false);
        int provinces = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, adj, visited);
            }
        }

        return provinces;
    }
};

*/