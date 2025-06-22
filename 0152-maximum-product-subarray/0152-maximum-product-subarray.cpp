class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        
        for(int i = 0; i < n; i++) {
            int mul = nums[i];
            maxi = max(maxi, mul);
            for(int j = i + 1; j < n; j++) {
                mul *= nums[j];
                maxi = max(maxi, mul);
            }
        }
        return maxi;
    }
};