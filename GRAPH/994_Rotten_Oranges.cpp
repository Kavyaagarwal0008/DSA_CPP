#include<bits/stdc++.h>
using namespace std; 

class Solution{
public:

    int orangesRotting(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        int countFresh=0;
        queue<pair< pair<int ,int>, int>> q;  //{{r,c} , t}
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==2){

                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                if(grid[i][j]==1){
                    countFresh++;
                }
                else{
                    visited[i][j]=0;
                }
            }

        }

        int time=0;
        int delrow[]={-1, 0 , 1 , 0};
        int delcol[]={0, 1, 0, -1};
        int cnt=0;
        while(!q.empty()){
            //first row and front element
            int r=q.front().first.first;
            int c=q.front().first.second;

            int t=q.front().second;

            time=max(time,t);
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){

                    q.push({{nrow,ncol}, t+1});
                    visited[nrow][ncol]=2;
                    cnt++;

                }
            }
            
        }
        if(cnt!=countFresh){
            return -1;
        }
        return time;

    }
};

int main(){
    Solution s;
    vector<vector<int>> grid={{0,1,2},{0,1,1},{2,1,1}};

    cout<<s.orangesRotting(grid)<<endl;
    return 0;
}