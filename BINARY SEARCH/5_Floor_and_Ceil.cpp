#include<bits/stdc++.h>
using namespace std;

int floor_x(int arr[],int n,int x){
    int low=0,high=n-1;
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]<=x){
            ans=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int ceil_x(int arr[],int n,int x){
    int low=0,high=n-1;
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]>=x){
            ans=arr[mid];
            
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
    int ans=floor_x(arr,n,x);
    int ans2=ceil_x(arr,n,x);
    cout<<"floor is "<<ans<<endl;
    cout<<"ceil is "<<ans2<<endl;
    return 0;

}