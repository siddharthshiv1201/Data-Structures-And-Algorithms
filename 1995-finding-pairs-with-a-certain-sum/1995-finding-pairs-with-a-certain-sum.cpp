class FindSumPairs {
public:
    vector<int>nums1;
    vector<int>nums2;
    unordered_map<int,int>mp1;
    unordered_map<int,int>mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(auto it : nums1) mp1[it]++;
        for(auto it : nums2) mp2[it]++;

    }
    
    void add(int index, int val) {
        int element = this -> nums2[index];
        int temp = element + val;
        // if(mp2.find(temp) != mp.end()){
        mp2[temp] += 1;
        mp2[element]--; 
        if(mp2[element == 0]) mp2.erase(this -> nums2[index]);

        this -> nums2[index] +=val;
    }
    
    int count(int tot) {
       
        int ans = 0;
        for( auto it:mp1){
            if(it.first < tot && mp2.find(tot - it.first ) != mp2.end()){
                ans = ans + (it.second*mp2[tot - it.first]);
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */