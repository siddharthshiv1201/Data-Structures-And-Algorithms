class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxElement = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            vector<char> v;
            for (int j = i; j < n; j++) {  
                if (find(v.begin(), v.end(), s[j]) == v.end()) {  
                    v.push_back(s[j]);
                } else {
                    break;  
                }
            }
            int x = v.size();
            maxElement = max(maxElement, x);
        }
        return maxElement;
    }
};
