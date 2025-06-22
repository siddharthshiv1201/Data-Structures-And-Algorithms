class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> rem1, rem2;

        for (int num : nums) {
            sum += num;
            if (num % 3 == 1) rem1.push_back(num);
            else if (num % 3 == 2) rem2.push_back(num);
        }

        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        if (sum % 3 == 0) {
            return sum;
        } else if (sum % 3 == 1) {
            int option1 = (rem1.size() >= 1) ? (sum - rem1[0]) : 0;
            int option2 = (rem2.size() >= 2) ? (sum - rem2[0] - rem2[1]) : 0;
            return max(option1, option2);
        } else { 
            int option1 = (rem2.size() >= 1) ? (sum - rem2[0]) : 0;
            int option2 = (rem1.size() >= 2) ? (sum - rem1[0] - rem1[1]) : 0;
            return max(option1, option2);
        }
    }
};