class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0;
        int maxSum=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            cursum=cursum+nums[i];
            maxSum=max(maxSum,cursum);
            if(cursum<0){
                cursum=0;
            }
        }
        return maxSum;
        
    }
};