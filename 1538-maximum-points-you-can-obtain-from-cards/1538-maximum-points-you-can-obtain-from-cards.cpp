class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        
        // Compute the sum of the first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        int maxSum = sum;
        
        // Try replacing elements from the end
        for (int i = 0; i < k; i++) {
            sum -= nums[k - 1 - i]; // Remove from the left
            sum += nums[n - 1 - i]; // Add from the right
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
