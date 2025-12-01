#include<bits/stdc++.h>
using namespace std;

int smallest_divisor(vector<int>&nums, int x){

    int n=nums.size();
    int maxi=*max_element(nums.begin(),nums.end());
    
    for(int d=1;d<=maxi;d++){
        int sum=0;

        for(int i=0;i<n;i++){
            sum+= ceil((double)(nums[i])/(double)(d));
        }

        if(sum<=x){
            return d;
        }
    }
    return -1;
}

int main(){
    vector<int>nums={1,2,5,9};
    int x=6;

    cout<<smallest_divisor(nums,x);
    return 0;
}