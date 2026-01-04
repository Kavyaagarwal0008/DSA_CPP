#include<bits/stdc++.h>
using namespace std;

// Brute force 
/*
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            int count = 0, sum = 0;
            for (int i = 1; i <= num; i++) {
                if (num % i == 0) {
                    count++;
                    sum += i;
                }
            }
            if (count == 4) totalSum += sum;
        }
        return totalSum;
    }
};
*/

class Solution {
public:
    bool isprime(int n){
        if(n<2){
            return false;

        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int sumFourDivisors(vector<int>& nums){
        int total=0;
        for(int x: nums){
            int sum=0;
            bool valid=false;

            //case 1 x= p*q
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    int j=x/i;
                    if(i!=j && isprime(i) && isprime(j)){
                        sum=1+i+j+x;
                        valid=true;
                    }
                    break;
                }
            }
            // case2 x=p^3
            int root=round(pow(x,1.0/3));
            if(root * root*root == x && isprime(root)){
                sum=1+root+root*root+ x;
                valid=true;
            }
            if(valid){
                total+=sum;
            }
        }
        return total;
    }
};


int main(){
    vector<int> nums={21,4,7};
    Solution s;
    cout<<s.sumFourDivisors(nums);

    return 0;
}