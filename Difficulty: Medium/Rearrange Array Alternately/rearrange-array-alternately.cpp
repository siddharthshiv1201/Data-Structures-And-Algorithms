//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void rearrange(vector<int>& arr) {

        // Your code here
        int n=arr.size();
        int s=0,e=n-1;
        sort(arr.begin(),arr.end());
        vector<int>ans;
        while(s<e)
        {
            ans.push_back(arr[e]);
            e--;
            ans.push_back(arr[s]);
            s++;
        }

//to handle the odd lengthed cases
        if(s==e)ans.push_back(arr[s]);
        arr=ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends