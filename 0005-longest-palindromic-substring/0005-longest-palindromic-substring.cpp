class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 0;

        // Helper function to expand around center
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return make_pair(left + 1, right - left - 1);
        };

        for (int i = 0; i < s.size(); i++) {
            // Check for odd-length palindrome
            auto [oddStart, oddLen] = expand(i, i);

            // Check for even-length palindrome
            auto [evenStart, evenLen] = expand(i, i + 1);

            // Update longest palindrome found
            if (oddLen > maxLen) {
                start = oddStart;
                maxLen = oddLen;
            }
            if (evenLen > maxLen) {
                start = evenStart;
                maxLen = evenLen;
            }
        }

        return s.substr(start, maxLen);
    }
};

