#include<bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n + 1, 0);

        for (auto &t : trust) {
            int a = t[0];
            int b = t[1];
            score[a]--;   // a trusts someone
            score[b]++;   // b is trusted
        }

        for (int i = 1; i <= n; i++) {
            if (score[i] == n - 1)
                return i;
        }

        return -1;
    }
int main(){
    int n=3;

    vector<vector<int>> trust= {
        {1,3},
        {2,3}
    };

    int result=findJudge(n,trust);
    cout<<result<<endl;

    return 0;
}