class Solution {
public:
    void findCombinations(int index, int k, int target, vector<int>& result, vector<vector<int>>& ans) {
        if (target == 0 && k == 0) { // Found a valid combination
            ans.push_back(result);
            return;
        }
        if (target < 0 || k < 0) return; // Prune invalid paths

        for (int i = index; i <= 9; i++) { // Numbers from 1 to 9
            result.push_back(i); // Take the current number
            findCombinations(i + 1, k - 1, target - i, result, ans); // Recur for next number
            result.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> result;
        findCombinations(1, k, n, result, ans);
        return ans;
    }
};
