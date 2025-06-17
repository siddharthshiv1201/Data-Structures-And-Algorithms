class Solution {
public:
    int bs(vector<int>& nums, int target, int l, int r){
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    int findMin(vector<int>& nums){
        int n = nums.size();
        int start = 0, end = n - 1;
        while(start <= end){
            if(nums[start] <= nums[end]) return start;

            int mid = start + (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]){
                return mid;
            }

            if(nums[mid] <= nums[end]){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int x = findMin(nums);
        int a1 = bs(nums, target, 0, x - 1);
        int a2 = bs(nums, target, x, n - 1);
        if(a1 == -1) return a2;
        return a1;
    }
};
