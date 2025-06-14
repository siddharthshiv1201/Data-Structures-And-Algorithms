class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        int platform =1;
        int result=1;
        int i=1;
        int j=0;
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                platform++;
                i++;
            }
            else{
                platform--;
                j++;
            }
            result=max(result,platform);
        }
        return result;
        
    }
};
