class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map1;

        for (int i = 0; i < nums.size(); i++) {
            map1[nums[i]]++;
        }

        vector<pair<int, int>> vec(map1.begin(), map1.end());
        

        sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });
        
        vector<int> result;
        for (int i = 0; i < k && i < vec.size(); i++) {
            result.push_back(vec[i].first);
        }
        
        return result;
    }
};
