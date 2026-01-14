#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //adjacency list 
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &t : times){
            adj[t[0]].push_back({t[1],t[2]});

        }
        //distance array
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        //MinHeap (distance , node)

        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;

        pq.push({0,k});

        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &it : adj[node]){
                int nextnode=it.first;
                int wt=it.second;
                if(time + wt < dist[nextnode]){
                    dist[nextnode]=time+wt;
                    pq.push({dist[nextnode],nextnode});

                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            
            }
            else{
                ans=max(ans,dist[i]);
            }
        }
        return ans;

    }
};

int main(){
    int n=4;
    int k=2;
    vector<vector<int>> times={ 
        {2,1,1},{2,3,1},{3,4,1}
    };
    Solution s;
    cout<<s.networkDelayTime(times,n,k);
    
    return 0;
}