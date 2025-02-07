class Solution {
public:
    void genper(vector<int> &nums, vector<vector<int>>& result){
        sort(nums.begin(),nums.end());
        do{
            result.push_back(nums);
        }
        while(next_permutation(nums.begin(),nums.end()));
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        genper(nums,result);
        return result;
        
        
    }
};