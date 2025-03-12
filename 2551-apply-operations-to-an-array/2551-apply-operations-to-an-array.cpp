class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> v;
    
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        vector<int> forother, forzero;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                forother.push_back(nums[i]);
            } else {
                forzero.push_back(nums[i]);
            }
        }


        forother.insert(forother.end(), forzero.begin(), forzero.end());

        return forother;
    }
};
