class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        unordered_map<int,int> map1,map2,map3;
        vector<int> ans;
        for(int x:arr1) map1[x]++;
        for(int x:arr2) map2[x]++;
        for(int x:arr3) map3[x]++;
        
        for(int x:arr1){
            if(map1[x]>0 && map2[x]>0 && map3[x]>0){
                ans.push_back(x);
                
                map1[x]=0;
                map2[x]=0;
                map3[x]=0;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};