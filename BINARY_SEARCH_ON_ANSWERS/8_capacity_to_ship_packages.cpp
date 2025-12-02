#include<bits/stdc++.h>
using namespace std;

int days_needed(vector<int>&nums, int capacity){

    int day=1,load=0;
    for(int x : nums){
        if(load+x>capacity){
            day++;
            load=x;
        }
        else{
            load+=x;
        }
    }
    return day;
}

int ship_with(vector<int>&nums, int d){
    int left=*max_element(nums.begin(),nums.end());
    int right=accumulate(nums.begin(),nums.end(),0);

    // for(int i=left;i<=right;i++){
    //     int needed=days_needed(nums,i);
    //     if(needed<=d){
    //         return i;
    //     }
    // }
    // return right;


    //OPTIMAL- USING BINARY SEARCH
    while(left<right){
        int mid = left + (right - left) / 2;

        int needed=days_needed(nums,mid);
        if(needed<=d){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return left;
    

}
int main(){
    vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    int days=5;

    cout<<ship_with(nums,days)<<endl;
    return 0;
}