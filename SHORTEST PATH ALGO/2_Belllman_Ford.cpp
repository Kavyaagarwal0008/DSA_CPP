#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    vector<int> bellmanford(int V, vector<vector<int>>& edges , int src){
        vector<int>dist(V,INT_MAX); //1e9

        dist[src]=0;

        //relax edges v-1 times 
        for(int i=1;i<=V-1;i++){
            for(auto &edge : edges){
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                if(dist[u] != INT_MAX && dist[u]+wt < dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }

        //neg cycle 
        for(auto &edge : edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            if(dist[u]!=INT_MAX && dist[u]+wt < dist[v]){
                cout<<"Negative cycle"<<endl;
                return {};
            }
        }
        return dist;
    }
};


int main() {
    Solution s;
    int V = 5;
    vector<vector<int>> edges = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };

    vector<int> ans = s.bellmanford(V, edges, 0);

    for(int d : ans)
        cout << d << " ";

    return 0;
}
