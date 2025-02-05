class Solution {
public:
    void helper(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& result) {
        // **Base case**: When we reach the end of the array
        if (i == nums.size()) {
            result.push_back(curr);
            return;
        }

        // **Include the current element**
        curr.push_back(nums[i]);  
        helper(nums, i + 1, curr, result);
        curr.pop_back();  // Backtrack

        // **Skip duplicate elements**
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;  // Move to the next unique element
        }

        // **Exclude the current element** and move to the next unique one
        helper(nums, i + 1, curr, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        helper(nums, 0, curr, result);
        return result;
    }
};