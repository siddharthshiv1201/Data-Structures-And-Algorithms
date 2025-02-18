//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
    vector<int> v1;
    unordered_map<int, int> freq;  // Hash map to store frequencies
    int distinct_count = 0;

    // Process first window
    for (int i = 0; i < k; i++) {
        if (freq[arr[i]] == 0) distinct_count++;
        freq[arr[i]]++;
    }
    v1.push_back(distinct_count);

    // Sliding window technique
    for (int i = k; i < arr.size(); i++) {
        // Remove element going out of window
        if (--freq[arr[i - k]] == 0) distinct_count--;

        // Add new element coming into the window
        if (freq[arr[i]]++ == 0) distinct_count++;

        v1.push_back(distinct_count);
    }

    return v1;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends