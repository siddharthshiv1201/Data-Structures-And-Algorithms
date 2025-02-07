class Solution {
public:
    void findCombinations(int index, int k, int target, vector<int>& result, vector<vector<int>>& ans) {
        if (target == 0 && k == 0) { 
            ans.push_back(result);
            return;
        }
        // if (target < 0 || k < 0) return;

        for (int i = index; i <= 9; i++) { 
            result.push_back(i); 
            findCombinations(i + 1, k - 1, target - i, result, ans); 
            result.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> result;
        findCombinations(1, k, n, result, ans);
        return ans;
    }
};
