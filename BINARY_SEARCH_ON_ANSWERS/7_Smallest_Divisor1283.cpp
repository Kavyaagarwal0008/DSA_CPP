#include<bits/stdc++.h>
using namespace std;

int sum_division(vector<int>&nums, int x){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=ceil((double)(nums[i])/x);

    }
    return sum;
}
int smallest_divisor(vector<int>&nums, int x){
    int n=nums.size();

    if(n>x){
        return -1;
    }
    int maxi=*max_element(nums.begin(),nums.end());
    
    int low=1,high=maxi;
    while(low<=high){
        int mid=(low+high)/2;

        if(sum_division(nums,mid)<=x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main(){
    vector<int>nums={1,2,5,9};
    int x=6;

    cout<<smallest_divisor(nums,x);
    return 0;
}