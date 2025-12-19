#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int row, int col,vector<vector<int>>& ans,vector<vector<int>>& image, int newColor,int delrow[],int delcol[],int iniColor) {

        int n = image.size();
        int m = image[0].size();

        ans[row][col] = newColor;

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {

                dfs(nrow, ncol, ans, image, newColor, delrow, delcol, iniColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        int iniColor = image[sr][sc];
        if(iniColor == newColor){ 
            return image;
        }

        vector<vector<int>> ans = image;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        dfs(sr, sc, ans, image, newColor, delrow, delcol, iniColor);
        return ans;
    }
};


/*

//USING BFS 
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor) {

        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];

        if (oldColor == newColor)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    image[nr][nc] == oldColor) {

                    image[nr][nc] = newColor;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};

*/

int main() {
    Solution sol;

    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    vector<vector<int>> result = sol.floodFill(image, 0, 0, 2);

    // Print result
    for(auto &row : result) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
