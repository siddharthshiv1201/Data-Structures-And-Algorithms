class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map1;
        if(s.size()==0) return 0;
        int i=0;
        int j=0;
        int maxi=INT_MIN;
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