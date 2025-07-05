class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> dict(501, 0);

        int maxi = -1;

        for(int i : arr){
            dict[i]++;
        }

        for(int i : arr){
            if(i == dict[i]){
                maxi = max(maxi, i);
            }
        }

        return maxi;
    }
};