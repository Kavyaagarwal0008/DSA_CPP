#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x){
            return x;

        }
        return parent[x]=find(parent[x]);

    }
    bool unite(int x, int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return false; //cycle
        }

        if(rank[px]<rank[py]){
            parent[px]=py;

        }
        else if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else{
            parent[py]=px;
            rank[px]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=1;i<=n;i++){
            parent[i]=i;

        }
        for(auto &e : edges){
            if(!unite(e[0],e[1])){
                return e;
            }
        }
        return {};
    }
};

int main(){
    Solution s;
    vector<vector<int>>edges={ {1,2},{1,3},{2,3} };

    vector<int>ans=s.findRedundantConnection(edges);
    for(int x: ans){
        cout<< x << " ";
    }
    return 0;
}