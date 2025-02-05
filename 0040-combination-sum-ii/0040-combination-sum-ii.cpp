class Solution {
public:
    void helper(int index, vector<int>& candidates, vector<int>& result, int sum, int target, vector<vector<int>>& ans) {
        if (sum == target) { // If sum matches target, store the subset
            ans.push_back(result);
            return;
        }
        if (index >= candidates.size() || sum > target) return; // Out of bounds or sum exceeded
        
        // Take the current element
        result.push_back(candidates[index]);
        helper(index + 1, candidates, result, sum + candidates[index], target, ans);
        result.pop_back(); // Backtrack

        // Skip the current element and move to the next index (avoid duplicates)
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }
        helper(index + 1, candidates, result, sum, target, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> result;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        helper(0, candidates, result, 0, target, ans);
        return ans;
    }
};