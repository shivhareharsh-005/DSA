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
    void solve(TreeNode* root1, TreeNode* root2,TreeNode* &root){
        if(!root1 && !root2) return;
        else if(root1 && !root2){
            TreeNode* node(new TreeNode(root1->val));
            root=node;
            solve(root1->left,root2,root->left);
            solve(root1->right,root2,root->right);
        }else if(root2 && !root1){
            TreeNode* node(new TreeNode(root2->val));
            root=node;
            solve(root1,root2->left,root->left);
            solve(root1,root2->right,root->right);
        }else{
            TreeNode* node(new TreeNode(root1->val+root2->val));
            root=node;
            solve(root1->left,root2->left,root->left);
            solve(root1->right,root2->right,root->right);
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root(nullptr);
        solve(root1,root2,root);
        return root;
    }
};