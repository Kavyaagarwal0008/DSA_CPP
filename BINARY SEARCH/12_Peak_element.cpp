#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid + 1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    Solution obj;
    cout << obj.findPeakElement(nums) << endl;
    return 0;
}