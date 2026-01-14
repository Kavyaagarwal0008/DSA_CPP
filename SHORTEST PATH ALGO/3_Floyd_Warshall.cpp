#include<bits/stdc++.h>
using namespace std;\

class Graph{
public:

    void floyd(vector<vector<int>>&dist){
        int V=dist.size();

        //intermediate node 
        for(int k=0;k<V;k++){
            //i source
            for(int i=0;i<V;i++){
                //j destinationn
                for(int j=0;j<V;j++){
                    //1e9 INT_MAX - skip invalid paths 
                    if(dist[i][k]==1e9 || dist[k][j]==1e9){

                        continue;
                    }
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        //negative detection 
        for(int i=0;i<V;i++){
            if(dist[i][i]<0){
                cout<<"Negative cycle detected "<<endl;

            }
        }
    }
};

int main(){

    const int INF = 1e9;

    vector<vector<int>> dist = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    Graph g;
    g.floyd(dist);

    for(auto &row : dist){
        for(int val : row){
            if(val==INF){
                cout<<"INF"<<endl;
            }
            else{
                cout<<val<<" ";

            }
        }
        cout<<endl;
    }
    return 0;

}