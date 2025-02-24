class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    int count = 0, oddCount = 0;
    int i = 0, j = 0;
    list<int> lst; // Stores indices of odd numbers

    while (j < nums.size()) {
        if (nums[j] % 2 != 0) {
            lst.push_back(j);
            oddCount++;
        }
        
        while (oddCount > k) { // Shrinking the window
            if (nums[i] % 2 != 0) {
                lst.pop_front();
                oddCount--;
            }
            i++;
        }
        
        if (oddCount == k) {
            count += (lst.front() - i + 1); // Add valid subarrays
        }
        
        j++; // Expand the window
    }
    
    return count;
}

};