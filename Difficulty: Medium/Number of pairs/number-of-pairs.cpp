//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
       int one=0,two=0,three=0,four=0;
        sort(brr.begin(),brr.end());
        
        for(auto it:brr){
            if(it==1) one++;
            else if(it==2) two++;
            else if(it==3) three++;
            else if(it==4) four++;
        }
        
        int n=arr.size(),m=brr.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=1){
                
                ans+=one;
                
                if(arr[i]==2){
                    ans-=(three+four);
                } 
                
                else if(arr[i]==3){
                    ans+=two;
                }
                
                ans+=m-(upper_bound(brr.begin(),brr.end(),arr[i])-brr.begin());
                
            }
            
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends