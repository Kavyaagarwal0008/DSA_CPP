#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);  // check last bit
        n >>= 1;           // right shift
    }
    return count;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Number of set bits in " << num << " = " << countSetBits(num) << endl;
    return 0;
}
