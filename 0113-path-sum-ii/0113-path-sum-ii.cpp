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
    vector<vector<int>>result;
    void solve(TreeNode* root, int targetSum, int sum, vector<int>temp){
        if(root == nullptr) return;
        temp.push_back(root->val);
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr && sum == targetSum){
            result.push_back(temp);
        }
        solve(root->left, targetSum, sum, temp);
        solve(root->right, targetSum, sum, temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int>temp;
        solve(root, targetSum, sum, temp);
        return result;
    }
};