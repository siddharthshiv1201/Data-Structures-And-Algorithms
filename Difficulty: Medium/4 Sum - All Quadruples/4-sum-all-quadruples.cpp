//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr[] : int input array of integers
    // target : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
    vector<vector<int>> result;
    int n = arr.size();
    
    // Sort the array to handle duplicates easily
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 3; i++) {
        // Avoid duplicates for the first number
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < n - 2; j++) {
            // Avoid duplicates for the second number
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            int left = j + 1, right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[j] + arr[left] + arr[right];

                if (sum == target) {
                    result.push_back({arr[i], arr[j], arr[left], arr[right]});

                    // Move left and right to skip duplicates
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    while (left < right && arr[right] == arr[right - 1]) right--;

                    left++;
                    right--;
                } 
                else if (sum < target) {
                    left++;  // Increase sum by moving left pointer
                } 
                else {
                    right--; // Decrease sum by moving right pointer
                }
            }
        }
    }
    
    return result;
}


};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(arr, d);
        sort(ans.begin(), ans.end());
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << endl;
        }
        if (ans.empty()) {
            cout << -1 << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends