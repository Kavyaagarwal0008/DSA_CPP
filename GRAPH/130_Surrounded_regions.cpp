#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void dfs(int row,int col , vector<vector<int>>& visited , vector<vector<char>>& mat , int delrow[] , int delcol[]){
        visited[row][col]=1;

        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && ncol>=0 && nrow< n && ncol<m && !visited[nrow][ncol] && mat[nrow][ncol]=='0' ){
                dfs(nrow , ncol , visited , mat , delrow , delcol);

            }
        }
    }
    vector<vector<char>> fill(int n , int m , vector<vector<char>> mat){
        vector<vector<int>> visited(n,vector<int>(m,0));

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        //first and last row 
        for(int j=0;j<m;j++){
            if(!visited[0][j] && mat[0][j]=='O'){
                dfs(0,j,visited,mat , delrow , delcol);
            }
            if(!visited[n-1][j]&& mat[n-1][j]=='O'){
                dfs(n-1,j,visited,mat , delrow , delcol);
            }
        }

        //first and last column 

        for(int i=0; i< n;i++){

            if(!visited[i][0] && mat[i][0]=='O'){
                dfs(i , 0 , visited , mat , delrow , delcol);
            }
            if(!visited[i][m-1] && mat[i][m-1]=='O'){
                dfs(i , m-1 ,visited , mat , delrow , delcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';

                }
            }
        }
        return mat;

    }
};
int main(){
    vector<vector<char>> mat={
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };
    int n=mat.size();
    int m=mat[0].size();
    Solution s;
    vector<vector<char>> ans= s.fill(n,m,mat);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}