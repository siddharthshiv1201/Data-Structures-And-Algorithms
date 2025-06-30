class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        vector<char> v;
        int n = max(word1.size(), word2.size());
        
        for (int i = 0; i < n; i++) {
            if (i < word1.size()) {
                v.push_back(word1[i]);
            }
            if (i < word2.size()) {
                v.push_back(word2[i]);
            }
        }
        
        string result = "";
        for (int i = 0; i < v.size(); i++) {
            result += v[i];
        }
        
        return result;
    }
};
