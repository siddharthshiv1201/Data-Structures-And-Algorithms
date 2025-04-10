class Solution {
public:
    // Better approach with O(n) TC and SC
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // if we found the ele in set then delete the ele in grp of 3 means
            // traverse them and get ceil val
            if (st.count(nums[i])) {
                return ceil((i + 1) / 3.0);
            }
            // if not present in set then insert it in set
            st.insert(nums[i]);
        }
        // if not then return 0
        return 0;
    }
};