//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
         int totalSum = 0;
    int leftSum = 0;
    int n = arr.size();

    // Step 1: Calculate total sum of the array
    for (int num : arr) {
        totalSum += num;
    }

    // Step 2: Traverse the array and check equilibrium condition
    for (int i = 0; i < n; i++) {
        // Check if left sum is equal to right sum
        if (leftSum == totalSum - leftSum - arr[i]) {
            return i; // Equilibrium index found
        }
        leftSum += arr[i]; // Update left sum
    }

    return -1; // No equilibrium index found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends