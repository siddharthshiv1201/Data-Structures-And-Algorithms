//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
    int count = 0;
    int i = 0;
    
    while (i < arr.size() - 1) {
        int jump = arr[i];
        if (jump == 0) return -1;  // Prevent getting stuck
        
        count++;
        int maxReach = i;  // Track the best position to jump next
        int bestIndex = i; // Store the best index to jump to

        for (int j = 1; j <= jump; j++) {
            if (i + j >= arr.size() - 1) return count; // If we can reach the end
            if (i + j + arr[i + j] > maxReach) { 
                maxReach = i + j + arr[i + j]; 
                bestIndex = i + j; // Select the best jump
            }
        }

        i = bestIndex; // Move to the optimal position
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
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends