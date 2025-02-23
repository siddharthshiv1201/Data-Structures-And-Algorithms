//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
    int k = pat.size();
    int n = txt.size();
    if (k > n) return 0;  // Edge case: If pattern is longer than text

    vector<int> patFreq(26, 0), windowFreq(26, 0);
    int count = 0;

    // Count frequency of characters in pattern and first window
    for (int i = 0; i < k; i++) {
        patFreq[pat[i] - 'a']++;
        windowFreq[txt[i] - 'a']++;
    }

    // Check the first window
    if (patFreq == windowFreq) count++;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowFreq[txt[i] - 'a']++;        // Add new character
        windowFreq[txt[i - k] - 'a']--;    // Remove old character

        if (patFreq == windowFreq) count++;
    }

    return count;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends