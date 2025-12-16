#include<iostream>

using namespace std;
int remove_setbits(int num){
    return (num&(num-1));
}

int main(){
    int a;
    cin>>a;
    int result=remove_setbits(a);
    cout<<result;
    return 0;
}