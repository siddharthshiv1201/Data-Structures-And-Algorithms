class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map1;
        for(int i=0; i<nums.size(); i++){
            map1[nums[i]]++;
        }
        int x=0;
        for(int i=0; i<nums.size(); i++){
            if(map1[nums[i]]<2){
                x=nums[i];
                break;
            }
        }
        return x;
        
    }
};