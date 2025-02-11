class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        
        for (int i = 0; i < n; i++) { 
            int sum = nums[i];
            
            while (i < n - 1 && nums[i] < nums[i + 1]) { 
                sum += nums[i + 1];
                i++; 
            }
            
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
