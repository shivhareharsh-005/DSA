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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>>q;
        q.push({root, 0});
        int maxwidth = 0;
        while(!q.empty()){
            int size = q.size();
            unsigned long long start = q.front().second;
            unsigned long long end = q.back().second;

            maxwidth = max(maxwidth, (int)(end-start+1));

            while(size--){
                auto temp = q.front();
                q.pop();

                if(temp.first->left){
                    q.push({temp.first->left, temp.second*2+1});
                }

                if(temp.first->right){
                    q.push({temp.first->right, temp.second*2+2});
                }
            }
        }
        return maxwidth;
    }
};