class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
            vector<long long>a(arr,arr+n);
            sort(a.begin(),a.end());
        
            int count=0;

            for(int i =0;i<n-2;i++){
            int j = i+1,k=n-1;
            
            while(j<k){
                int cur = a[i]+a[j]+a[k];
                if(cur < sum) {
                    count += (k-j);
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return count;
    }
};