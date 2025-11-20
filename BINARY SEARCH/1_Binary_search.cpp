#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 
        if (arr[mid] == x)
            return mid;        
        else if (arr[mid] < x)
            low = mid + 1;     
        else
            high = mid - 1;    
    }
    return -1;                 
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, n, x);
    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";
    return 0;
}
