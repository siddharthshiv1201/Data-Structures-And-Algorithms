class Solution {
public:
     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int>li;
        vector<int>ans;
        int i=0,j=0;
        
        while(j<nums.size()){
            // list me check krenge ki list k pehle wale elements agr list of j se chote hai to unhe pop krdo but aage wale ko nhai kyunki wo kbhi maximum ho skte hai.
            while(li.size()>0 && li.back()<nums[j]){
                li.pop_back();
            }
            li.push_back(nums[j]);
            
            if(j-i+1 < k)j++;
            
            else if(j-i+1 == k){
                ans.push_back(li.front());
                
                if(nums[i] == li.front()){
                    li.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
         
    }
};