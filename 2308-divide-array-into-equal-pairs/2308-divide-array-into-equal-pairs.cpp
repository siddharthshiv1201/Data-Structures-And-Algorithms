class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> map1;
        for(int i=0; i<nums.size(); i++){
            map1[nums[i]]++;
        }
        for(auto x: map1){
            if(x.second%2!=0){
                return false;
            }
        }
        return true;
    }
};