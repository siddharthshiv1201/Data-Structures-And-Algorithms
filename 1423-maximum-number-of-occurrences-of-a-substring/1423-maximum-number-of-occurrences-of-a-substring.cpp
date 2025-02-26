class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<char, int> map1; // Tracks character frequency in the window
        unordered_map<string, int> map2; // Stores substring frequencies
        int uniqueChars = 0, maxFreq = 0;
        int i = 0;

        for (int j = 0; j < s.size(); j++) {
            // Expand the window: Add s[j] to map1
            if (++map1[s[j]] == 1) {
                uniqueChars++; // New unique character added
            }

            // Shrink the window if it exceeds minSize
            if (j - i + 1 > minSize) {
                if (--map1[s[i]] == 0) {
                    uniqueChars--; // Remove unique character
                }
                i++; // Shrink window
            }

            // Check if the current window is valid
            if (j - i + 1 == minSize && uniqueChars <= maxLetters) {
                string sub = s.substr(i, minSize);
                map2[sub]++; // Store substring frequency
                maxFreq = max(maxFreq, map2[sub]); // Track max frequency
            }
        }

        return maxFreq;
    }
};
