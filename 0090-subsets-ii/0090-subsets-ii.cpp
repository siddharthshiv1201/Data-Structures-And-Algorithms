class Solution {
public:
    vector<vector<int>> result;

    void helper(vector<int>& nums, vector<int>& temp, int index) {
        // Base case
        if (index >= nums.size()) {
            result.push_back(temp);
            return;
        }
        // Include the current element
        temp.push_back(nums[index]);
        helper(nums, temp, index + 1);
        temp.pop_back();  // Backtrack
        // Skip duplicate elements
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        // Exclude the current element and move to the next
        helper(nums, temp, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        vector<int> temp;
        helper(nums, temp, 0);
        return result;
    }
};
