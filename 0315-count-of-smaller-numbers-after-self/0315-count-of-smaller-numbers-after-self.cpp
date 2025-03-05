// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         // TLE
//     //     vector<int> v;
//     //     int i = 0;
//     //     while (i < nums.size()) {
//     //         int j = i + 1, count = 0;
//     //         while (j < nums.size()) {  
//     //             if (nums[i] > nums[j]) {
//     //                 count++;  
//     //             }
//     //             j++;
//     //         }
//     //         v.push_back(count);  // Store count instead of values
//     //         i++;
//     //     }
//     //     return v;
//     // }
// };
constexpr int min_neg = -10000;
constexpr int max_range = 20001;
class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        array<int, max_range> fen {};
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; --i) {
            nums[i] -= min_neg;

            int ind = nums[i] - 1;
            while(ind >= 0)
                ans[i] += fen[ind],
                ind &= ind + 1,
                --ind;

            ind = nums[i];
            while(ind < max_range)
                ++fen[ind],
                ind |= ind + 1;
        }

        return ans;
    }
};