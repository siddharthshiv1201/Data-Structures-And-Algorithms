class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        unordered_map<char, int> map1;
        int i = 0, j = 0;
        
        while (j < s.size()) {
            map1[s[j]]++; // Expand window by adding character at j
            
            // Check if all 'a', 'b', and 'c' are present in the window
            while (map1['a'] > 0 && map1['b'] > 0 && map1['c'] > 0) {
                count += s.size() - j; // Count valid substrings
                map1[s[i]]--; // Shrink window from the left
                i++;
            }
            
            j++; // Expand window
        }
        
        return count;
    }
};
