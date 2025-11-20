// Time Complexity

// Best case: O(1)
// Average case: O(log n)
// Worst case: O(log n)

// Space (iterative): O(1)
// Space (recursive): O(log n)


#include <bits/stdc++.h>
using namespace std;


int binarySearchRecursive(int arr[], int low, int high, int x) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        return binarySearchRecursive(arr, mid + 1, high, x);
    else
        return binarySearchRecursive(arr, low, mid - 1, x);
}
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    int result = binarySearchRecursive(arr, 0, n - 1, x);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
