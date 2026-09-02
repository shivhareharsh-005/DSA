class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int first =0, sec=0;
        while(first < nums.size()){
            if(nums[first] % 2 == 0){
                swap(nums[first], nums[sec]);
                sec++;
            }
            first++;
        }
        return nums;
    }
};