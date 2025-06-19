class Solution {
public:
    int firstElement(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : arr) {
            freq[num]++;
        }

        // Find the first element with frequency == k
        for (int num : arr) {
            if (freq[num] == k) {
                return num;
            }
        }

        // If no such element exists
        return -1;
    }
};
