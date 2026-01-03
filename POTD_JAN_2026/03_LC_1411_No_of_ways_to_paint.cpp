#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long same=6;  //ABA
        long diff=6;  //ABC
        for (int i=2;i<=n;i++) {
            long newSame =(same * 3 + diff * 2)%MOD;
            long newDiff =(same * 2 + diff * 2)%MOD;
            same=newSame;
            diff=newDiff;
        }
        return (same + diff) % MOD;
    }
};


//br4te f6rce 
/*
class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> validRows;
    int n;

    bool valid(vector<int>& row){
        return (row[0]!=row[1] && row[1]!=row[2]);
    }

    bool comp(vector<int>& a, vector<int>& b){
        for(int i=0;i<3;i++){
            if(a[i]==b[i]){
                return false;
            }
        }
        return true;
    }

    int dfs(int row ,vector<int>& prev){
        if(row==n){
            return 1;
        }
        int ways=0;
        for (auto& curr : validRows) {
            if (prev.empty() ||comp(prev, curr)) {
                ways = (ways + dfs(row + 1, curr)) % MOD;
            }
        }
        return ways;
    }
    int numOfWays(int N) {
        n=N;
        for(int a=1;a<=3;a++){
            for(int b=1;b<=3;b++){
                for(int c=1;c<=3;c++){
                    vector<int> row={a,b,c};
                    if(valid(row)){
                        validRows.push_back(row);
                    }
                }
            }
        }
        vector<int> empty;
        return dfs(0,empty);
        
    }
};
*/
int main(){
    int n=1;
    Solution s;
    cout<<s.numOfWays(n);
    return 0;
}