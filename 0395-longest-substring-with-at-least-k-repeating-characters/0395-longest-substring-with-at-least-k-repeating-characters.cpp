class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() == 0 || k > s.size()) return 0;

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;  // Count frequencies of each character
        }

        // Find the first character that appears less than k times
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] < k) {
                // Recursively solve for left and right substrings
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i + 1), k);
                return max(left, right);
            }
        }

        // If every character appears at least k times, return the full length
        return s.size();
    }
};
