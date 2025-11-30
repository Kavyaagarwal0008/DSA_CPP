#include<bits/stdc++.h>
using namespace std;

int pos(int arr[],int n,int x){
    int low=0,high=n-1,ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            ans=mid;
            low=mid+1;
        }
        else if(arr[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int ans=pos(arr,n,x);
    cout<<"index is "<<ans<<endl;
    return 0;

}