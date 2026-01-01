#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<vector<int>> revAdj(n);
        vector<int> indegree(n,0);

        //reverse graph
        for(int u=0;u<n;u++){
            for(int v : graph[u]){
                revAdj[v].push_back(u);
                indegree[u]++;
            }
        }

        //queue for kahn's
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);

            }
        }

        //BFS
        vector<int>safe;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            safe.push_back(node);

            for(int prev : revAdj[node]){
                indegree[prev]--;
                if(indegree[prev]==0){
                    q.push(prev);

                }
            }
        }

        sort(safe.begin(),safe.end());
        return safe;
    }
};

int main(){

    Solution s;
    vector<vector<int>> graph={
        {1,2},{2,3},{5},{0},{5},{},{}
    };

    vector<int>ans=s.eventualSafeNodes(graph);
    for(int x : ans){
        cout<< x << " ";
    }
    return 0;
}