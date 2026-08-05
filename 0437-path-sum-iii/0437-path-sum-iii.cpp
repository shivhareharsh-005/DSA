/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int total = 0;

    void solve(TreeNode* root, long long targetSum, long long currSum) {
        if (root == nullptr)
            return;

        currSum += root->val;

        if (currSum == targetSum)
            total++;

        solve(root->left, targetSum, currSum);
        solve(root->right, targetSum, currSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return 0;

        solve(root, targetSum, 0);

        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return total;
    }
};