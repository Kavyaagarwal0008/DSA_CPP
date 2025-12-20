#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    void dfs(int row , int col , vector<vector<int>>& grid, vector<vector<int>>& visited){

        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){

                dfs(nrow,ncol,grid,visited);
            }
        }
        
    }
    int numEnclaves(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        //boundary row
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !visited[0][j]){
                dfs(0,j,grid,visited);

            }
            if(grid[n-1][j]==1 && !visited[n-1][j]){
                dfs(n-1,j,grid,visited);

            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(i,0,grid,visited);
            }
            if(grid[i][m-1]==1 && !visited[i][m-1]){
                dfs(i,m-1,grid,visited);

            }
        }
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1 && !visited[i][j]){
                    count++;

                }
            }
        }
        return count;
    }
};

int main(){
    vector<vector<int>> grid={
      {0,0,0,0},
      {1,0,1,0},
      {0,1,1,0},
      {0,0,0,0}
    };

    Solution s;
    int ans= s.numEnclaves(grid);
    cout<<ans<<endl;
}