//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
         static bool comparator(string& a, string& b) {
    return (a + b) > (b + a); // Custom sorting order
}

string findLargest(vector<int>& arr) {
    vector<string> s1;
    
    for (int num : arr) {
        s1.push_back(to_string(num));
    }

    sort(s1.begin(), s1.end(), comparator); // Sort based on concatenation logic

    // If largest element is "0", return "0" (handles cases like {0, 0, 0})
    if (s1[0] == "0") {
        return "0";
    }

    string result = "";
    for (string& num : s1) {
        result += num;
    }

    return result;
        

        
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

        Solution ob;
        string ans = ob.findLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends