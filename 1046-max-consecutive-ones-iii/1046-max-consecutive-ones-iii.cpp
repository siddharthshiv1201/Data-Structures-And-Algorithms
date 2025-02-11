class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxCount = 0;

        for (int i = 0; i < n; i++) {  
            int count = 0;
            int flips = k;
            int flipIndex = -1; 

            for (int j = i; j < n; j++) {  
                if (nums[j] == 1) {
                    count++;  
                } else if (flips > 0) {  
                    flips--;  
                    count++;  
                    if (flipIndex == -1) flipIndex = j;  
                } else {
                    break;  
                }
            }
            maxCount = max(maxCount, count);
            if (flipIndex != -1) i = flipIndex;  
        }

        return maxCount;
    }
};
