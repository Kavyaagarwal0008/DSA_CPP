#include<bits/stdc++.h>
using namespace std;

bool powerof_two(int n){
    int a=n&(n-1);
    return (a==0);
}
int main(){
    int n;
    cin>>n;
    cout<<powerof_two(n);
    return 0;
}