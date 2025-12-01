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
    int maxi=*max_element(nums.begin(),nums.end());
    for(int i=1;i<=maxi;i++){
        int hours=calculatehours(nums,i);
        if(hours<=h){
            return i;
        }
    }
    return maxi;
}

int main(){
    vector<int>piles={3,6,7,11};
    int h=8;
    cout<<koko(piles,h)<<endl;
    return 0;
}