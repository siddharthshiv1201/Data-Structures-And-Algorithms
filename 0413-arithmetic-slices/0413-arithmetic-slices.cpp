class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        if (n < 3) return 0;  // Need at least 3 elements for arithmetic slices
        
        int i = 0, j = 1;
        int diff = nums[1] - nums[0];  // Track the common difference
        int streak = 0;  // Count valid arithmetic slices

        while (j < n - 1) {
            if (nums[j + 1] - nums[j] == diff) {  // If sequence continues
                streak++;
                count += streak;  // Add valid sequences
            } else {  // If sequence breaks
                streak = 0;
                diff = nums[j + 1] - nums[j];  // Reset the common difference
            }
            j++;  // Move to the next element
        }

        return count;
    }
};
