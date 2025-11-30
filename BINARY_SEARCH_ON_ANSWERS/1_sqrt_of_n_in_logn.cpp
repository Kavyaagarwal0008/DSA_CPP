#include<iostream>
using namespace std;

int sqrt_bs(int n){
    int ans=0;
    for(int i =1;i<=n;i++){
        if((long long)i*i<=n){
            ans=i;
        }
        else{
            break;
        }
    }
    return ans;
}
int main(){

    int n;
    cin>>n;
    cout<<sqrt_bs(n)<<endl;
    return 0;
}
// O(n)
// O(1)