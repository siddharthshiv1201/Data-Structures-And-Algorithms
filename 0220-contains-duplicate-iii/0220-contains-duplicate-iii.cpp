class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& arr, int indexDiff, int valueDiff) {
        set<long long> window; // Ordered set to maintain the window
        for (int i = 0; i < arr.size(); i++) {
            auto it = window.lower_bound((long long)arr[i] - valueDiff);
            if (it != window.end() && *it <= (long long)arr[i] + valueDiff) {
                return true;
            }
            
            window.insert(arr[i]); // Insert the current element
            
            // Maintain the window of size at most `indexDiff`
            if (i >= indexDiff) {
                window.erase(arr[i - indexDiff]);
            }
        }
        return false;
    }
};
