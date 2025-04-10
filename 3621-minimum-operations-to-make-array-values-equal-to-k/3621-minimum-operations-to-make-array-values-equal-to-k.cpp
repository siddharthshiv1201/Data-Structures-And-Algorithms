class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int count=0;

        for(auto it = s.begin(); it != s.end(); it++){
            if(*it > k){
                count++;
            }
            else if(*it==k){
                continue;
            }
            else return -1;
        }
        return count;
    }
};