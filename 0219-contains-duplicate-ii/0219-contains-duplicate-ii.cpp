class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int j = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (set.count(nums[i])) {
                if (abs(i - j) <= k) return true;
                set.erase(nums[j]);
                j++;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};