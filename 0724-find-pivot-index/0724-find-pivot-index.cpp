class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0, leftSum = 0;
        
        for (int num : nums) {
            totalSum += num;  // Calculate total sum of array
        }

        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;  // Found the pivot index
            }
            leftSum += nums[i];  // Update left sum for next iteration
        }
        
        return -1;  // No pivot index found
    }
};
