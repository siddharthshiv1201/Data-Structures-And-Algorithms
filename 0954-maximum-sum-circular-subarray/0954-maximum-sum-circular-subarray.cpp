// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int n = nums.size();
//         int max_sum = INT_MIN;
        
//         for (int i = 0; i < n; i++) {
//             int current_sum = 0;
//             for (int j = 0; j < n; j++) {
//                 int index = (i + j) % n;  
//                 current_sum += nums[index];
//                 if (current_sum > max_sum) {
//                     max_sum = current_sum;
//                 }
//             }
//         }
        
//         return max_sum;
//     }
// };

/// TLE 
// TLE 

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxsum = nums[0];
        int curmax = 0;
        int minsum = nums[0];
        int curmin = 0;

        for(int& i : nums){
            curmax = max(curmax + i, i);
            maxsum = max(maxsum, curmax);
            
            curmin = min(curmin + i, i);
            minsum = min(minsum, curmin);
            total += i;
        }

        return (maxsum > 0) ? max(maxsum, total-minsum) : maxsum;
    }
};