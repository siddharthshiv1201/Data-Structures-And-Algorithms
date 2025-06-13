class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                count++;
                v.push_back(count);
            }
            else{
                count=0;
            }    
        }
        if(v.empty()) return 0;
        else
        return *max_element(v.begin(),v.end());    
    }
};