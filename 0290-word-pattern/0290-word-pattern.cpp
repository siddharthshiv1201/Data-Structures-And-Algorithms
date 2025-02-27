#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map1;  // Maps pattern chars to words
        unordered_map<string, char> map2;  // Maps words to pattern chars
        vector<string> words;
        stringstream ss(s);
        string word;

        // Split 's' into words
        while (ss >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.size()) return false;  // Must match in length

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];

            // Check if the pattern character already has a mapping
            if (map1.count(c) && map1[c] != words[i]) return false;

            // Check if the word already maps to a different pattern character
            if (map2.count(words[i]) && map2[words[i]] != c) return false;

            // Create the mappings
            map1[c] = words[i];
            map2[words[i]] = c;
        }

        return true;
    }
};
