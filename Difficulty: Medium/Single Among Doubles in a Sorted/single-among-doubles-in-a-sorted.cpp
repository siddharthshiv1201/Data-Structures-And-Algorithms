//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findOnce(vector<int>& arr) {
        // code here.
        if(arr.size()==1){
            return arr[0];
        }
        unordered_map<int,int> map1;
        for(int i=0; i<arr.size(); i++){
            map1[arr[i]]++;
        }
        for(int i=0; i<arr.size(); i++){
            if(map1[arr[i]]<2){
                return arr[i];
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.findOnce(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends