#include <vector>

using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // Edge case: negative goal not possible
        int i = 0, sum = 0, count = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while (sum > goal) { // Shrink the window
                sum -= nums[i];
                i++;
            }

            count += (j - i + 1); // Count all valid subarrays ending at j
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
