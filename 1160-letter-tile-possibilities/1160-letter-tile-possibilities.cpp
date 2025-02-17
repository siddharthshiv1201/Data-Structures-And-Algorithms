class Solution {
public:
    void backtrack(string& tiles, unordered_map<char, int>& freq, int& count) {
        for (auto& pair : freq) {
            if (pair.second > 0) {
                // Choose the current character
                count++;
                freq[pair.first]--;  // Decrease frequency for the current character
                backtrack(tiles, freq, count);  // Recurse
                freq[pair.first]++;  // Backtrack
            }
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char c : tiles) {
            freq[c]++;  // Count frequency of each character
        }

        int count = 0;
        backtrack(tiles, freq, count);  // Start backtracking
        return count;
    }
};
