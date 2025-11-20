#include<bits/stdc++.h>
using namespace std;

int lowerBound(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]>=x){
            return i;
        }
    }
    return n;
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

    int ans=lowerBound(arr,n,x);
    cout<<"lower bound is "<<ans<<endl;
    return 0;

}