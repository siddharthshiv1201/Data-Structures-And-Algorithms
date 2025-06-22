class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n=s.size();
        int i=0;
        int j=0;
        int maxi=0;
        unordered_map<char,int> map1;
        while(j<s.size()){
            map1[s[j]]++;
            while(map1[s[j]]>1){
                map1[s[i]]--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
