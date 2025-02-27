#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i = 0, sum = 0;
        int n = arr.size();
        vector<int> best(n, INT_MAX);  // Best min subarray length up to each index
        int minLen = INT_MAX;

        // First pass: Find the smallest subarray sum at each index
        for (int j = 0; j < n; j++) {
            sum += arr[j];

            while (sum > target) { // Shrink window if sum exceeds target
                sum -= arr[i];
                i++;
            }

            if (sum == target) {
                int len = j - i + 1;
                if (i > 0 && best[i - 1] != INT_MAX) {  // Ensure non-overlapping condition
                    minLen = min(minLen, best[i - 1] + len);
                }
                best[j] = min(j > 0 ? best[j - 1] : INT_MAX, len);
            } else {
                best[j] = j > 0 ? best[j - 1] : INT_MAX;
            }
        }

        return (minLen == INT_MAX) ? -1 : minLen;
    }
};
