#include<bits/stdc++.h>
using namespace std;

//brute force 
/*
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    return nums[i];
            }
        }
        return -1; // never reached
    }
};

*/

// optimal 
/*class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums) {
            if (s.count(x))
                return x;
            s.insert(x);
        }
        return -1;
    }
};
*/
//optimal with sc O(1);
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2]){
                return nums[i];
            }
        }
        return nums.back();
    }
};


int main(){
    Solution s;
    vector<int> nums={2,1,2,5,3,2};
    cout<<s.repeatedNTimes(nums);
    return 0;
}