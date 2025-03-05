class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> even, odd, result(nums.size());  

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }

        int evenIdx = 0, oddIdx = 0;  // Separate indices for even and odd
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                result[i] = even[evenIdx++];
            } else {
                result[i] = odd[oddIdx++];
            }
        }

        return result;
    }
};
