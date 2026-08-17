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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        map<int, vector<int>>mp;
        while(!q.empty()){
            int size = q.size();
            vector<pair<int, int>> level;
            while(size--){
                auto p = q.front();
                q.pop();
                TreeNode* temp = p.first;
                int x = p.second;
                level.push_back({x, temp->val});
                if(temp->left)
                q.push({temp->left, x-1});
                if(temp->right)
                q.push({temp->right, x+1});
            }
            sort(level.begin(), level.end());
            for(auto & i : level){
                mp[i.first].push_back(i.second);
            }
        }
        for(auto & it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};