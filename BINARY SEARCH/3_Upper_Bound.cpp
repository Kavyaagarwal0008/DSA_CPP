#include<bits/stdc++.h>
using namespace std;

int upperBound(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]>x){
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

    int ans=upperBound(arr,n,x);
    cout<<"upper bound is "<<ans<<endl;
    return 0;

}