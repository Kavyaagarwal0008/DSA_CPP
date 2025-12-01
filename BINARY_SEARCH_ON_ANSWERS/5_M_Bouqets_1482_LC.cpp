#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int>&nums, int day , int m , int k){
    int cnt=0,n=nums.size();
    int no_of_Bouqet=0;
    for(int i=0;i<n;i++){
        if(nums[i]<=day){
            cnt++;
        }
        else{
            no_of_Bouqet+=(cnt/k);
            cnt=0;
        }
    }
    no_of_Bouqet+=(cnt/k);
    if(no_of_Bouqet>=m){
        return true;
    }
    else{
        return false;
    }
}

int min_days(vector<int>&nums, int m, int k){
    int total=m*k;
    if(total>nums.size()){
        return -1;
    }
    int mini=*min_element(nums.begin(),nums.end());
    int maxi=*max_element(nums.begin(),nums.end());

    // for(int i=low;i<=high;i++){
    //     if(possible(nums,i,m,k)){
    //         return i;
    //     }
    // }



    // OPTIMAL-BINARY SEARCH

    int low=mini,high=maxi;
    int result=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(nums,mid,m,k)){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return result;
}

int main(){
    vector<int>nums={1,10,3,10,2};
    int m=3;
    int k=1;
    cout<<min_days(nums,m,k)<<endl;
    return 0;

}

