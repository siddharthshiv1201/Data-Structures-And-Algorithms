class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        
        // Iterate through each character from 'a' to 'z'
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int minFreq = INT_MAX;
            
            // Check frequency of the character in each word
            for (int i = 0; i < words.size(); i++) {
                int count = 0;
                
                // Count occurrences of ch in words[i]
                for (int j = 0; j < words[i].size(); j++) {
                    if (words[i][j] == ch) count++;
                }
                
                minFreq = min(minFreq, count); // Update minimum frequency
            }
            
            // If the character is present in all words, add it to the result
            for (int i = 0; i < minFreq; i++) {
                result.push_back(string(1, ch));
            }
        }
        
        return result;
    }
};
