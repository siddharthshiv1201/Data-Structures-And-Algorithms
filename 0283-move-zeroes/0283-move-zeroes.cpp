class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                count++;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                v.push_back(nums[i]);
            }
        }
        for(int i=0; i<count; i++){
            v.push_back(0);
        }
        nums=v;
    }
};