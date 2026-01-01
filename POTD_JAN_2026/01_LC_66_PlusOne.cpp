#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>ans(n+1,0);
        for(int i=n-1;i>=0;i--){
           
            if(digits[i]<9){
                digits[i]++;
                return digits; //only last to update

            }
            digits[i]=0;
            
        }
        //all are 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main(){
    vector<int>num={1,2,3,9};
    Solution s;
    vector<int>ans=s.plusOne(num);

    for(int x : ans){
        cout<<x<< " ";
    }
    return 0;
}

//brute - array to digit , +1 , then back to array
/*
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;

        // convert to number
        for (int d : digits) {
            num = num * 10 + d;
        }

        num += 1;

        // convert back to digits
        vector<int> ans;
        while (num > 0) {
            ans.push_back(num % 10);
            num /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

*/
/*
Optimal
Start from last digit
If digit < 9 → add 1 and stop
If digit == 9 → make it 0 and carry forward
If all digits are 9 → add 1 at front
*/