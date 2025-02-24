//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalElements(vector<int> &arr) {
    unordered_map<int, int> map1;
    int i = 0, j = 0;
    int maxi = 0;
    
    while (j < arr.size()) {
        map1[arr[j]]++;

        // Shrink the window if more than 2 distinct elements
        while (map1.size() > 2) {
            map1[arr[i]]--;
            if (map1[arr[i]] == 0) {
                map1.erase(arr[i]);
            }
            i++;
        }

        // Update the maximum length of valid subarray
        maxi = max(maxi, j - i + 1);

        // Move the right pointer
        j++;
    }

    return maxi;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends