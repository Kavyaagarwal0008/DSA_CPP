#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int answerLevel = 1;
        long long maxSum = LLONG_MIN;

        while (!q.empty()) {
            int size = q.size();
            long long currSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                currSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                answerLevel = level;
            }

            level++;
        }

        return answerLevel;
    }
};
int main() {
    /*
        Example Tree:
                1
               / \
              7   0
             / \
            7  -8
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution sol;
    int result = sol.maxLevelSum(root);

    cout << "Level with maximum sum: " << result << endl;

    return 0;
}