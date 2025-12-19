#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    vector<vector<int>> nearest(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> visited(n , vector<int>(m,0));
        vector<vector<int>> distance(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){ //grid[i][j]==0 for nearest0 

                    q.push({{i,j},0});
                    visited[i][j]=1;
                }

                else{
                    visited[i][j]=0;

                }
            }
        }

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            distance[row][col]=steps;

            q.pop();
            

            for(int i=0;i<4;i++){
                int nr=row+delrow[i];
                int nc=col+delcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && visited[nr][nc]==0){
                    visited[nr][nc]=1;
                    q.push({{nr,nc},steps+1});

                }
            }
        }
        return distance;

    }

};

int main(){
    Solution s; 
    vector<vector<int>>grid={ {0,0,0},{0,1,0},{1,0,1} };
    vector<vector<int>>ans=s.nearest(grid);

    for(auto &row : ans) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}