class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>&nums, int i,vector<int>temp){
        if(i >= nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, i+1, temp);
        temp.pop_back();
        int index =i+1;
        while(index<nums.size() && nums[index] == nums[i]){
            index++;
        }
        solve(nums,index, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(), nums.end());
        solve(nums, 0, temp);
        return result;
    }
};