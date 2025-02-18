//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> &arr, int k) {
     vector<vector<int>> v;
    unordered_map<int, int> freq;

    // Count occurrences of each remainder
    for (int num : arr) {
        freq[num % k]++;
    }

    vector<int> v1;
    for (int i = 0; i < arr.size(); i++) {
        int rem = arr[i] % k;
        int complement = (k - rem) % k;

        if (freq[rem] == 0) continue;  // Skip if already paired

        if (rem == 0 || rem == complement) {
            if (freq[rem] % 2 != 0) return false;  // Must be even count
        } else {
            if (freq[rem] != freq[complement]) return false;  // Mismatch in pairs
        }

        v.push_back({arr[i], complement});
        freq[rem]--;
        freq[complement]--;
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            v1.push_back(v[i][j]);
        }
    }

    return true;
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
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        bool ans = obj.canPair(arr, k);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends