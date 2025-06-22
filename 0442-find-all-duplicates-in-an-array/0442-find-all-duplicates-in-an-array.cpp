class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> map1;
        vector<int> v;
        for(int num:nums){
            map1[num]++;
        }
        for(const auto& pair: map1){
            if(pair.second>1){
                v.push_back(pair.first);
            }
        }
        return v;
        
    }
};