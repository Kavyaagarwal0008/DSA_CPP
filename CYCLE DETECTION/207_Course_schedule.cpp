#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        //compute indegree
        for(int i=0;i<prerequisites.size();i++){
            for(int next : adj[i]){
                indegree[next]++;
            }      
        }
        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;

            for(int nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);

                }
            }
        }
        return count == numCourses;
    }
};

int main(){
    int num=2;
    vector<vector<int>> p={{1,0}};

    Solution s;
    cout<<s.canFinish(num,p);
    return 0;
}