#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    int dfs(int row , int col , vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        //boundary+water track
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==0){
            return 0;
        }
        grid[row][col]=0;

        int area=1;
        area+=dfs(row-1 , col ,grid); //up
        area += dfs(row + 1, col, grid); // down
        area += dfs(row, col - 1, grid); // left
        area += dfs(row, col + 1, grid); // right

        return area;
    }
    int maxAreaIsland(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1){
                    maxArea=max(maxArea , dfs(i , j, grid));

                }
            }
        }
        return maxArea;
    }
};

int main(){
    vector<vector<int>> grid={
      {0,0,1,0,0,0,0,1,0,0,0,0,0},
      {0,0,0,0,0,0,0,1,1,1,0,0,0},
      {0,1,1,0,1,0,0,0,0,0,0,0,0},
      {0,1,0,0,1,1,0,0,1,0,1,0,0},
      {0,1,0,0,1,1,0,0,1,1,1,0,0},
      {0,0,0,0,0,0,0,0,0,0,1,0,0},
      {0,0,0,0,0,0,0,1,1,1,0,0,0},
      {0,0,0,0,0,0,0,1,1,0,0,0,0}  
    };

    Solution s;
    int ans= s.maxAreaIsland(grid);
    cout<<ans<<endl;
}