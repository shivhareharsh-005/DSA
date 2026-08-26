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
    void inorder(TreeNode* root, vector<int>&temp){
        if(root == nullptr)
           return;

        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }
    void checkArray(vector<int>&temp){
        vector<int>index;
        int i = 0;
        while(i < temp.size()-1){
            if(temp[i] > temp[i+1]){
                index.push_back(i);
            }
            i++;
        }
        if(index.size() == 2){
            swap(temp[index[0]], temp[index[1]+1]);
        } else {
            swap(temp[index[0]], temp[index[0]+1]);
        }
    }
    int j = 0;
    void modifyTree(TreeNode* root, vector<int>&temp){
        
        if(root == nullptr)
        return ;

        modifyTree(root->left, temp);
        root->val = temp[j++];
        modifyTree(root->right, temp);
    }
    void recoverTree(TreeNode* root) {
        vector<int>temp;
        inorder(root, temp);
        checkArray(temp);
        modifyTree(root, temp);
    }
};