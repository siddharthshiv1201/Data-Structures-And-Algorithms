class Solution {
public:
    int maxDistance(vector<int>& arr) {
        unordered_map<int, int> firstIndex;
        int maxi = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (firstIndex.find(arr[i]) == firstIndex.end()) {
                firstIndex[arr[i]] = i;
            } else {
                maxi = max(maxi, i - firstIndex[arr[i]]);
            }
        }
        return maxi;
    }
};
