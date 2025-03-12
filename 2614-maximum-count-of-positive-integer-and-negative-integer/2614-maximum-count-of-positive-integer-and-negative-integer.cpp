class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countpos=0;
        int countneg=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) countpos++;
            else if(nums[i]<0)countneg++;
        }
        return max(countpos,countneg);
        
    }
};