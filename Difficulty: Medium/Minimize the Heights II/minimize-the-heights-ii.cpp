//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
    int n = arr.size();
    if (n == 1) return 0; // If there's only one element, no difference

    // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    // Step 2: Compute the initial difference
    int minVal = arr[0];
    int maxVal = arr[n - 1];
    int minDiff = maxVal - minVal;

    // Step 3: Modify the heights
    for (int i = 1; i < n; i++) {
        int newMin = min(arr[0] + k, arr[i] - k);
        int newMax = max(arr[i - 1] + k, arr[n - 1] - k);

        if (newMin < 0) continue; // Heights cannot be negative

        minDiff = min(minDiff, newMax - newMin);
    }

    return minDiff;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
        cout << '~' << endl;
    }
    return 0;
}
// } Driver Code Ends