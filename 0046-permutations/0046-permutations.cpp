class Solution {
public:
 void generatePermutations(vector<int>& nums, vector<vector<int>>& result) {
        sort(nums.begin(), nums.end()); 
        do {
            result.push_back(nums); 
        } while (next_permutation(nums.begin(), nums.end())); 
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generatePermutations(nums, result);
        return result;
    }
};