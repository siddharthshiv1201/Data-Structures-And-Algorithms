class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v1; 
        vector<int> v2; 
        vector<int> v3; 
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                v1.push_back(nums[i]);
            } 
            else if (nums[i] == pivot) {
                v2.push_back(nums[i]);
            } 
            else {
                v3.push_back(nums[i]);
            }
        }
        vector<int> result;
        result.insert(result.end(), v1.begin(), v1.end());
        result.insert(result.end(), v2.begin(), v2.end());
        result.insert(result.end(), v3.begin(), v3.end());

        return result;
    }
};
