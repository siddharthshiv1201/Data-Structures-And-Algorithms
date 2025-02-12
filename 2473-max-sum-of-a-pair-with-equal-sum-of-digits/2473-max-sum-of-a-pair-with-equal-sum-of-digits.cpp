// class Solution {
// public:
// int digitSum(int n){
//     int sum=0;
//     while(n>0){
//         sum+= n%10;
//         n=n/10;
//     }
//     return sum;
// }
//     int maximumSum(vector<int>& nums) {
//         int maxCount=-1;
//         int sum=0;
//         int n=nums.size();
//         for(int i=0; i<n; i++){
//             int x=0;
//             x=digitSum(nums[i]);
//             for(int j=0; j<n; j++){
//                 int y=0;
//                 sum=nums[i]+nums[j];
//                 y=digitSum(nums[j]);
//                 if(i!=j && x==y){
//                     maxCount=max(maxCount,sum);
                    
//                 }
//             }
//         }
//         return maxCount;

        
//     }
// };
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp; // Stores {digitSum -> maxNumber with that digitSum}
        int maxCount = -1;

        for (int num : nums) {
            int sum = digitSum(num);

            if (mp.find(sum) != mp.end()) {
                maxCount = max(maxCount, num + mp[sum]); // Compare with existing max pair sum
            }

            mp[sum] = max(mp[sum], num); // Store the maximum number for this digit sum
        }

        return maxCount;
    }
};