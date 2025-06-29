
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // code here
        int n=arr.size();
        int i=0;
        int j=1;
        sort(arr.begin(),arr.end());
        while(i<n && j<n){
            if(i!=j && arr[j]-arr[i]==x){
                return true;
            }
            else if(arr[j]-arr[i]<x){ 
                j++;
            }
            else{
                i++;
            }
        }
        return false;
        
    }
};
