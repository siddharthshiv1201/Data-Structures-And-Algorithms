class Solution {
public:
    bool canWePlaced(vector<int> &arr, int dist, int cow){
        int last=arr[0];
        int cntCow=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last>=dist){
                cntCow++;
                last=arr[i];
            }
            if(cntCow>=cow) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1;
        int high=position[n-1]-position[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canWePlaced(position,mid,m)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};