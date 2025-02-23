//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
    unordered_map<char, int> map1;
    int i = 0, j = 0;
    int maxi = -1;
    
    while (j < s.length()) {
        map1[s[j]]++;

        if (map1.size() < k) {
            j++;
        } 
        else if (map1.size() == k) {
            maxi = max(maxi, j - i + 1);
            j++;
        } 
        else if (map1.size() > k) {
            while (map1.size() > k) {
                map1[s[i]]--;
                if (map1[s[i]] == 0) {
                    map1.erase(s[i]);
                }
                i++;
            }
            j++; 
        }
    }
    return maxi;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends