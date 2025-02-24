class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal == 0) return countZeroSubarrays(nums); 
        
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0, sum = 0;

        while (j < n) {
            sum += nums[j];

            while (sum > goal && i <= j) {  
                sum -= nums[i];
                i++;
            }

            if (sum == goal) {
                int temp = i;
                while (temp <= j && nums[temp] == 0) {
                    count++;
                    temp++;
                }
                count++;
            }

            j++;
        }

        return count;
    }

    
    int countZeroSubarrays(vector<int>& nums) {
        int count = 0, zeroCount = 0;

        for (int num : nums) {
            if (num == 0) {
                zeroCount++; 
                count += zeroCount;
            } else {
                zeroCount = 0; 
            }
        }

        return count;
    }
};
