#include<bits/stdc++.h>
using namespace std;

bool power_four(int x){
    int a= x&(x-1);
    return ((a==0) && ((x-1)%3==0));
}
int main(){
    int n;
    cin>>n;
       
    cout<<power_four(n);
    return 0;
}