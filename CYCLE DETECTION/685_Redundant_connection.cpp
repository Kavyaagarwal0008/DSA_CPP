#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int>parentUF;
    int find(int x){
        if(parentUF[x]==x){
            return x;
        }
        return parentUF[x]=find(parentUF[x]);

    }

    bool unite(int u , int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            return false;
        }
        parentUF[v]=u;
        return true;

    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1,0);
        parentUF.resize(n+1);

        for(int i=1;i<=n;i++){
            parentUF[i]=i;
        }
        vector<int>cand1,cand2;
        //check for node with 2 parent 
        for(auto &e: edges){
            int u=e[0],v=e[1];
            if(parent[v]==0){
                parent[v]=u;
            }

            else{
                //first edge
                cand1={parent[v],v};
                cand2=e;
                e[1]=0; // remove second temp.
            }
        }
        //union find
        for(auto &e:edges){
            if(e[1]==0){
                continue;
            }
            if(!unite(e[0],e[1])){
                //cycle detected
                if(cand1.empty()){
                    return e;// case 1 cycle only
                }
                return cand1; //case 3 cycle with 2 parent
            }
        }
        //no cycle remove second parent 
        return cand2; // case 2 2 parent no cycle 
    }
};


int main(){
    Solution s;
    vector<vector<int>>edges={ {1,2},{1,3},{2,3} };

    vector<int>ans=s.findRedundantDirectedConnection(edges);
    for(int x: ans){
        cout<< x << " ";
    }
    return 0;
}