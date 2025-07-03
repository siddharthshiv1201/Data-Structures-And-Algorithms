class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 1);
        
        // Compute prefix products (left to right)
        int prefix = 1;
        for(int i = 0; i < n; i++){
            res[i] = prefix;
            prefix *= arr[i];
        }
        
        // Compute suffix products (right to left) and combine
        int suffix = 1;
        for(int i = n - 1; i >= 0; i--){
            res[i] *= suffix;
            suffix *= arr[i];
        }
        
        return res;
    }
};