#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int x : row) {
                if (x < 0) negCount++;
                sum += abs(x);
                minAbs = min(minAbs, abs(x));
            }
        }

        if (negCount % 2 == 0)
            return sum;
        else
            return sum - 2LL * minAbs;
    }
};

int main() {
    int n;
    cout << "Enter size of matrix (n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    long long result = sol.maxMatrixSum(matrix);

    cout << "Maximum Matrix Sum = " << result << endl;

    return 0;
}