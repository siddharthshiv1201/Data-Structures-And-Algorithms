class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        // Finding max and min values and their indices
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();

        // Ensure minIndex is always smaller than maxIndex for correct calculations
        if (maxIndex < minIndex) swap(maxIndex, minIndex);

        // Three possible deletion approaches
        int removeFromFront = maxIndex + 1;
        int removeFromBack = n - minIndex;
        int removeBothSides = (minIndex + 1) + (n - maxIndex);

        return min({removeFromFront, removeFromBack, removeBothSides});
    }
};
