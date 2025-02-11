class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        vector<char> v;

        for (int i = 0; i < n; i++) {
            v.push_back(word[i]);
            
            if (word[i] == ch) {  
                reverse(v.begin(), v.end());  
                return string(v.begin(), v.end()) + word.substr(i + 1); 
            }
        }

        return word; 
    }
};
