#include<bits/stdc++.h>
using namespace std;

int calculatehours(vector<int>&nums, int hour){
    int total=0;
    for(int x:nums){
        total+=(x+hour-1)/hour;
    }
    return total;

}
int koko(vector<int>&nums,int h){
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int ans=high;

    while(low<=high){
        int mid=low+(high-low)/2;
        long long hours=calculatehours(nums,mid);
        if(hours<=h){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int>piles={3,6,7,11};
    int h=8;
    cout<<koko(piles,h)<<endl;
    return 0;
}