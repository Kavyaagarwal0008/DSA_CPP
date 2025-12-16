#include<iostream>

using namespace std;
bool setbits(int num, int i){
    int a=1<<i;
    if(num&a){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int a,i;
    cin>>a>>i;
    bool result=setbits(a,i);
    cout<<result;
    return 0;
}