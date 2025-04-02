class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxVal=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<nums.size(); k++){
                    if(i<j && j<k){
                    long long maxi = (1LL * (nums[i] - nums[j])) * nums[k];
                    maxVal=max(maxVal,maxi);
                    }
                }
            }
        }
        return maxVal;
        
    }
};