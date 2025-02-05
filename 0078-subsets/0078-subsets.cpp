class Solution {
public:
    void helper(vector<int>& nums, int i, vector<int> curr, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(curr);
            return;
        }

        helper(nums, i + 1, curr, result);

        curr.push_back(nums[i]);  
        helper(nums, i + 1, curr, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        helper(nums, 0, curr, result);
        return result;
    }
};
