//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
       int i=0,j=0;
       queue<int> q;
       vector<int> v;
       while(j<arr.size()){
           if(arr[j]<0){
               q.push(arr[j]);
           }
           
           if(j-i+1<k){
               j++;
           }
           else if(j-i+1==k){
               if(q.size()==0){
                   v.push_back(0);
               }
               else{
                   v.push_back(q.front());
                   if(arr[i]==q.front()){
                       q.pop();
                   }
               }
               i++;
               j++;
           }
       }
       return v;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends