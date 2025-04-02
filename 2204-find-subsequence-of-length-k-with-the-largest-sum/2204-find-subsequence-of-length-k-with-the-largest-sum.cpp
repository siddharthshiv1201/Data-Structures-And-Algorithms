class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> copy=nums;
        sort(copy.begin(),copy.end());
        vector<int> ans;
        unordered_map<int,int> map1;
        for(int i=0 ;i<k; i++){
            map1[copy[n-1-i]]++;
        }

        for(int i=0; i<n; i++){
            if(map1[nums[i]]>0){
                ans.push_back(nums[i]);
                map1[nums[i]]--;
                if(ans.size()==k) break;
            }
        }
        return ans;
    }
};