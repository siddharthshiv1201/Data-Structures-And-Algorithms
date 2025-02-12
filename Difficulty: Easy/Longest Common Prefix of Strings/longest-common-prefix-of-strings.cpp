//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        if (arr.empty()) return ""; // Edge case: empty list

    string result = ""; // Stores the common prefix
    int n = arr.size(); // Number of strings
    int minLength = arr[0].length(); // Start with the length of the first string

    // Find the minimum length string to avoid out-of-bounds errors
    for (int i = 1; i < n; i++) {
        if (arr[i].length() < minLength) {
            minLength = arr[i].length();
        }
    }

    // Iterate over characters up to the minimum length string
    for (int i = 0; i < minLength; i++) {
        char currentChar = arr[0][i]; // Take character from the first string

        // Compare with the same index of other strings
        for (int j = 1; j < n; j++) {
            if (arr[j][i] != currentChar) { // Mismatch found
                return result; // Return result so far
            }
        }

        // If all strings have the same character, append to result
        result += currentChar;
    }

    return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        string ans = ob.longestCommonPrefix(arr);
        if (ans.empty())
            cout << "\"\"";
        else
            cout << ans;
        cout << endl;
    }
}

// } Driver Code Ends