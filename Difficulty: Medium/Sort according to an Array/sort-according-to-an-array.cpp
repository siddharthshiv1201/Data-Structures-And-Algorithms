//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code here
       unordered_map<int, int> freq;

    // Step 1: Count the frequency of each element in A1
    for (int i = 0; i < A1.size(); i++) {
        freq[A1[i]]++;
    }

    vector<int> result;

    // Step 2: Add elements from A1 according to A2's order
    for (int i = 0; i < A2.size(); i++) {
        int num = A2[i];
        if (freq.find(num) != freq.end()) {
            for (int j = 0; j < freq[num]; j++) {
                result.push_back(num);
            }
            freq.erase(num); // Remove from map after processing
        }
    }

    // Step 3: Store remaining elements (not in A2) in a separate vector
    vector<int> remaining;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        int num = it->first;
        int count = it->second;
        for (int j = 0; j < count; j++) {
            remaining.push_back(num);
        }
    }

    // Step 4: Sort the remaining elements
    sort(remaining.begin(), remaining.end());

    // Step 5: Append sorted remaining elements to the result
    for (int i = 0; i < remaining.size(); i++) {
        result.push_back(remaining[i]);
    }

    return result;
    } 
};

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends