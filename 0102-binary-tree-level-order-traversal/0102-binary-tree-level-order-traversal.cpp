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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == nullptr) return {};
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            vector<int>level;
            int size = q.size();
            while(size --){
                temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp ->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};