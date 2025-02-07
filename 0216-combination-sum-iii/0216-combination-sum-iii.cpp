class Solution {
public:
    void solve(int index, int k, int sum, int target, vector<int> temp, vector<vector<int>>& ans) {
        // Base cases
        if (sum > target || k < 0) return;  // Invalid case
        if (sum == target && k == 0) {  
            ans.push_back(temp);
            return;
        }

        // If index > 9, no numbers left to pick
        if (index > 9) return;

        // **Choice 1: Take the number**
        temp.push_back(index);
        solve(index + 1, k - 1, sum + index, target, temp, ans);
        
        // **Choice 2: Skip the number**
        temp.pop_back();  // (Optional here since we're passing temp by value)
        solve(index + 1, k, sum, target, temp, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, 0, n, temp, ans);
        return ans;
    }
};
