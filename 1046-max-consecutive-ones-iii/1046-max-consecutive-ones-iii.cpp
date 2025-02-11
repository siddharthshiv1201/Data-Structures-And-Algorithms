class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxCount = 0;

        for (int i = 0; i < n; i++) {  // Outer loop till n-1
            int count = 0;
            int flips = k;
            int flipIndex = -1;  // Mark where we start flipping

            for (int j = i; j < n; j++) {  // Inner loop j = i to n-1
                if (nums[j] == 1) {
                    count++;  // If it's 1, just count
                } else if (flips > 0) {  
                    flips--;  // If it's 0, flip it to 1
                    count++;  
                    if (flipIndex == -1) flipIndex = j;  // Mark first flip position
                } else {
                    break;  // Stop when we have no flips left
                }
            }

            maxCount = max(maxCount, count);

            if (flipIndex != -1) i = flipIndex;  // Start next iteration from first flipped zero
        }

        return maxCount;
    }
};
