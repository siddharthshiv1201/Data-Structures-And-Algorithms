class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()<=2){
            return {nums[0],nums[1]};
        }
        vector<int> v;
        unordered_map<int,int> map1;
        for(int i=0; i<nums.size(); i++){
            map1[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(map1[nums[i]]<2){
                v.push_back(nums[i]);
            }
        }
        return v;
        
    }
};