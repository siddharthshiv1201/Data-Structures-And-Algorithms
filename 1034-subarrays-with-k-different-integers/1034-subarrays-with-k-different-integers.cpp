class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    
private:
    int atMostK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int count = 0, i = 0;
        unordered_map<int, int> map1;
        
        for (int j = 0; j < nums.size(); j++) {
            map1[nums[j]]++;
            
            while (map1.size() > k) {
                map1[nums[i]]--;
                if (map1[nums[i]] == 0) {
                    map1.erase(nums[i]);
                }
                i++;
            }
            
            count += (j - i + 1);
        }
        
        return count;
    }
};
