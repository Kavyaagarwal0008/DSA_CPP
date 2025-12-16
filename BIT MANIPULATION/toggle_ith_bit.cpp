#include<iostream>

using namespace std;
int toggle_setbits(int num, int i){
    int a=1<<i;
    return num^a;
    
}

int main(){
    int a,i;
    cin>>a>>i;
    int result=toggle_setbits(a,i);
    cout<<result;
    return 0;
}