#include<bits/stdc++.h>
using namespace std;

// int count_bits(int n){
//     int count=0;
//     while(n>1){
//         if(n&1==1){ //odd number last bit is alaways 1
//             count+=1;
//             n=n/2;
//         }
//     }
//     return count + 1;
// }
// int count_bits(int n){
//     int count=0;
//     while(n>1){ṇ
//         count+=(n&1); //odd number last bit is alaways 1
          
//         n=n>>1;//n=n/2
        
//     }
//     return count + 1;
// }

int count_bits(int n){
    int count=0;
    while(n!=0){
        n=n&(n-1);
        count++;  
    }
    return count;
}
int main(){
    int n;
    cin>>n;
       
    cout<<count_bits(n);
    return 0;
}