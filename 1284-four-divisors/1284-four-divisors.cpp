// class Solution {
// public:
//     int Div(int n){
//         int count=0;
//         int sum=0;
//         for(int i=1; i<=n; i++){
//             if(n%i==0){
//                 sum+=i;
//                 count++;
//             }
//         }
//         if(count==4){
//             return sum;
//         }
//         return 0;

//     }
//     int sumFourDivisors(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> v;
//         for(int i=0; i<n; i++){
//             int x=Div(nums[i]);
//             v.push_back(x);
//         }
//         int sum2=0;
//         for(int i=0; i<v.size(); i++){
//             sum2+=v[i];
//         }
//         return sum2;
        
//     }
// };
// tle
class Solution {
public:
    int Div(int n){
        int count = 0;
        int sum = 0;

        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                int j = n / i;

                if(i == j){
                    count++;
                    sum += i;
                } else {
                    count += 2;
                    sum += i + j;
                }

                if(count > 4) return 0; // early exit
            }
        }

        return (count == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;

        for(int i = 0; i < n; i++){
            int x = Div(nums[i]);
            v.push_back(x);
        }

        int sum2 = 0;
        for(int i = 0; i < v.size(); i++){
            sum2 += v[i];
        }

        return sum2;
    }
};
