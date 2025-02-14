//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int toyCount(int N, int k, vector<int> arr)
    {
         sort(arr.begin(), arr.end());

    int count = 0, sum = 0;

    // Iterate through sorted prices and buy until budget is exhausted
    for (int i = 0; i < N; i++) {
        if (sum + arr[i] <= k) {
            sum += arr[i]; // Spend money on this toy
            count++;       // Increase toy count
        } else {
            break; // Stop if we can't afford the next toy
        }
    }

    return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.toyCount(N, K, arr)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends