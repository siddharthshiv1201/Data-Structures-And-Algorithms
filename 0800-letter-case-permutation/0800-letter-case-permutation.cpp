class Solution {
public:
void helper(string& s, int i, string curr, vector<string>& result) {
        //base 
        if (i == s.length()) {
            result.push_back(curr);
            return;
        }

        // if its a digit
        if (isdigit(s[i])) {
            helper(s, i + 1, curr + s[i], result);
        }
        // if its a character 
        else {
            helper(s, i + 1, curr + (char)tolower(s[i]), result);  // Lowercase
            helper(s, i + 1, curr + (char)toupper(s[i]), result);  // Uppercase
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        helper(s, 0, "", result);
        return result;

        
    }
};