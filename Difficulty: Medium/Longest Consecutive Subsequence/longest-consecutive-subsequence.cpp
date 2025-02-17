//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
    if (arr.empty()) return 0;  // Edge case: If array is empty

    sort(arr.begin(), arr.end());  // Sort array
    int longest = 1, count = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) continue;  // Skip duplicates

        if (arr[i] == arr[i - 1] + 1) {  
            count++;  // Increase count for consecutive numbers
        } else {
            longest = max(longest, count);  // Update longest sequence
            count = 1;  // Reset count
        }
    }
    
    return max(longest, count);  // Final check for max sequence
}


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends