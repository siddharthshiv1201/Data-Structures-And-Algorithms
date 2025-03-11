class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        unordered_map<char, int> map1;
        int i = 0, j = 0;
        
        while (j < s.size()) {
            map1[s[j]]++; 

            while (map1['a'] > 0 && map1['b'] > 0 && map1['c'] > 0) {
                count += s.size() - j;
                //shrink window
                map1[s[i]]--; 
                i++;
            }
            
            j++; // Expand window
        }
        
        return count;
    }
};
