#include <iostream>
#include <algorithm>  // for reverse
using namespace std;

string tobinary(int n) {
    string res = "";
    if (n == 0) return "0"; // handle zero case
    
    while (n > 0) {
        if (n % 2 == 1)
            res += '1';
        else
            res += '0';
        n = n / 2;
    }
    reverse(res.begin(), res.end()); // reverse once after loop
    return res;
}

int main() {
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;

    string binary = tobinary(num);
    cout << "Binary: " << binary << endl;

    return 0;
}
