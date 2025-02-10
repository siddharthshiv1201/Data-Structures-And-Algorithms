class Solution {
public:
    int singleNumber(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    unordered_map<int, int> map1; // Fixed variable name
    for (int i = 0; i < nums.size(); i++) {
        map1[nums[i]]++; // Fixed incorrect map name
    }
    int x = 0;
    for (int i = 0; i < nums.size(); i++) { // Fixed incorrect 'n' usage
        if (map1[nums[i]] < 2) { // Fixed condition
            x = nums[i]; // Assign the unique number
            break; // Exit loop once found
        }
    }
    return x;
}

};