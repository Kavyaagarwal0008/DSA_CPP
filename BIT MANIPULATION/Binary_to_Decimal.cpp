#include<iostream>
using namespace std;

int todecimal(string num){
    int len=num.length();
    int p2=1,x=0;
    for(int i=len-1;i>=0;i--){
        if(num[i]=='1'){
            x+=p2;
        }
        p2=p2*2;
    }
    return x;

}
int main(){
    string s;
    cin>>s;
    int result=todecimal(s);
    cout<<result<<endl;

    return 0;

}