class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, int i, int n, int target,
               int sum, vector<int>& temp) {

        if (sum == target) {
            result.push_back(temp);
            return;
        }

        if (i >= n || sum > target)
            return;

        // Include
        temp.push_back(candidates[i]);
        solve(candidates, i + 1, n, target, sum + candidates[i], temp);
        temp.pop_back();

        // Skip duplicates in Exclude branch
        int index = i + 1;
        while (index < n && candidates[index] == candidates[i]) {
            index++;
        }

        // Exclude
        solve(candidates, index, n, target, sum, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        solve(candidates, 0, candidates.size(), target, 0, temp);

        return result;
    }
};