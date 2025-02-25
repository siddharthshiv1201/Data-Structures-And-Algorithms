class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini=INT_MAX;
        int i=0;
        int j=0;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j];

            if(sum>=target){
                while(sum>=target){
                    mini=min(mini,j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }


            j++;
        }
        if(mini==INT_MAX){
            return 0;
        }
        return mini;
        
    }
};