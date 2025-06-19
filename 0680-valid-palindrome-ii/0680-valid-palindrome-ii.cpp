class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        int count = 0;

        while (left <= right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else if (count < 1) {
                // \U0001f6e0 Check full substring, not just one character
                if (isPalindrome(s, left + 1, right)) {
                    count++;
                    left++;  // simulate deletion at left
                }
                else if (isPalindrome(s, left, right - 1)) {
                    count++;
                    right--; // simulate deletion at right
                }
                else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};
