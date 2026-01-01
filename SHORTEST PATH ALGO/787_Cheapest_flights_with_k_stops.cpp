#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<vector<pair<int,int>>>adj(n);
        for(auto &f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }

        //cost node stops 
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});

        vector<int>dist(n,INT_MAX);
        dist[src]=0;

        while(!q.empty()){

            auto front=q.front();
            q.pop();

            int cost=front.first;
            int node=front.second.first;
            int stops=front.second.second;
            if(stops>k){
                continue;
            }

            for(auto it : adj[node]){
                int adjnode=it.first;// next dest node
                int e=it.second; //cost to next dest

                if(cost+e < dist[adjnode] && stops<=k){

                    dist[adjnode]=cost+e;
                    q.push({stops+1, {adjnode, cost+e}});

                }
            }
        }
        if(dist[dst]==1e9){
            return -1;

        }
        return dist[dst];


    }
};

int main(){

    Solution s;
    int n=4;
    vector<vector<int>>flights={ {0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200} };
    int src=0;
    int dst=3;
    int k=1;
    cout<<s.findCheapestPrice(n,flights,src,dst,k);

    return 0;
}