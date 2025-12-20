#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int>q;
        for(int i=0 ; i<numCourses ;i++){
            if(indegree[i]==0){
                q.push(i);

            }
        }
        vector<int> order;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);

            for(int next : adj[node]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);

                }
            }

        }
        if(order.size()==numCourses){
            return order;

        }

        return {};
    }
};

int main(){

    vector<vector<int>> preq={
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };
    int num=4;
    Solution s;
    vector<int>ans=s.findOrder(num,preq);

    for(int x:ans){
        cout<< x << " ";
    }

    return 0;
}