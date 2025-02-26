class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int j = 0, i = 0;
        int maxi = 1; // At least one element is always a valid turbulence subarray
        int count = 1; // Start with one element

        while (j < arr.size() - 1) {  // Ensure j+1 is within bounds
            if ((arr[j] > arr[j + 1] && (j == 0 || arr[j - 1] < arr[j])) || 
                (arr[j] < arr[j + 1] && (j == 0 || arr[j - 1] > arr[j]))) {
                count++; // Extend the turbulence window
            } else if (arr[j] == arr[j + 1]) {
                count = 1; // Reset if two elements are equal
                i = j + 1; // Move the start of the window
            } else {
                count = 2; // Reset but keep the last two elements
                i = j; 
            }

            maxi = max(maxi, count); // Update max turbulence size
            j++;
        }

        return maxi;
    }
};
