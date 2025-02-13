//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int> v1;
        for(int i=0; i<arr1.size(); i++){
            v1.push_back(arr1[i]);
        }
        for(int i=0; i<arr2.size(); i++){
            v1.push_back(arr2[i]);
        }
        sort(v1.begin(),v1.end());
        int n=v1.size()/2;
        // if(v1.size()%2==0){
        //     return v1[n];
        // }
        
            return v1[n-1]+v1[n];
        
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl << "~\n";
    }
}
// } Driver Code Ends