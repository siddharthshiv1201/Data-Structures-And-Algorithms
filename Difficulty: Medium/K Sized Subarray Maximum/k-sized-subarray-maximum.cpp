//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // TLE
        // int n=arr.size();
        // vector<int> v1;
        // vector<int> v2;
        // for(int i=0; i<=n-k; i++){
        //     v1.clear();
        //     for(int j=i; j<i+k; j++){
        //         v1.push_back(arr[j]);
        //     }
        //     int x=*max_element(v1.begin(),v1.end());

        //     v2.push_back(x);
        // }
        // return v2;
        
        // OPTIMISED
        int n = arr.size();
    vector<int> v2;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        // Remove elements out of the current window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Remove elements smaller than the current one (they will never be the max)
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        // Add current element index
        dq.push_back(i);

        // Store the max of the window (only from index k-1 onwards)
        if (i >= k - 1)
            v2.push_back(arr[dq.front()]);
    }

    return v2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends