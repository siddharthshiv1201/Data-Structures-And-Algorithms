// User function template for C++
class Solution {
  public:
   int findKRotation(vector<int> &arr) {
    int n = arr.size();
    int start = 0, end = n - 1;

    while (start <= end) {
        if (arr[start] <= arr[end]) return start; // already sorted part

        int mid = start + (end - start) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;

        if (arr[mid] >= arr[start])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return 0;
}


};
