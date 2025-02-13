//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // TLE
       
    //     vector<vector<int>> v;
    // for (int i = 0; i < arr.size(); i++) {
    //     vector<int> u;
    //     for (int j = i; j < arr.size(); j++) {  // Fix loop range (should start from `i`)
    //         u.push_back(arr[j]);  // Add elements to the subarray
            
    //         // Check if the subarray sum is 0
    //         int sum = accumulate(u.begin(), u.end(), 0);
    //         if (sum == 0) {
    //             v.push_back(u);
    //         }
    //     }
    // }
    // return v.size();
    
    // OPTIMISED
     unordered_map<int, int> prefixSumCount;
    int sum = 0, count = 0;

    prefixSumCount[0] = 1; // To count subarrays starting from index 0

    for (int num : arr) {
        sum += num;

        // If sum has been seen before, it means a subarray with sum 0 exists
        if (prefixSumCount.find(sum) != prefixSumCount.end()) {
            count += prefixSumCount[sum];
        }

        // Store the prefix sum count
        prefixSumCount[sum]++;
    }

    return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends