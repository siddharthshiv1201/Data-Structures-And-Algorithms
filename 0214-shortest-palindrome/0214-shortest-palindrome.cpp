class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int j = 0; // Pointer for the longest palindrome prefix

        // Reverse matching process
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == s[j]) {
                j++;
            }
        }

        // If the entire string is already a palindrome
        if (j == n) {
            return s;
        }

        // Find the unmatched suffix
        string suffix = s.substr(j);
        reverse(suffix.begin(), suffix.end());

        // Recursively apply the solution to the prefix
        string prefix = shortestPalindrome(s.substr(0, j));

        // Combine the parts to form the shortest palindrome
        return suffix + prefix + s.substr(j);
    }
};