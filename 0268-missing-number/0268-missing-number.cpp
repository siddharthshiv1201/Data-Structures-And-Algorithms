class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin() ,nums.end());
         if(nums[n-1]<n){
            return n;
        }
        for(int i=0; i<nums.size(); i++){
            if(i!=nums[i]){
                return i;
            }


        }
                    return 0;

        
    }
};