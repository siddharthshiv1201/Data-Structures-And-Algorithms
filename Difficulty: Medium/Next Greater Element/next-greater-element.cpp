class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> nge(n);
        stack<int> st;
        nge[n-1]=-1;
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<=arr[i])
            st.pop();
            
            if(st.empty()) nge[i]=-1;
            
            else{
                nge[i]=st.top();
            }
            st.push(arr[i]);
        }
        return nge;
    }
};