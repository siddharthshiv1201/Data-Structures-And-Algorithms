class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {  // Keep reducing until a single-digit number
            int sum = 0;
            while (num > 0) {
                sum += num % 10; // Extract last digit and add to sum
                num /= 10;       // Remove last digit
            }
            num = sum; // Update num with the sum of digits
        }
        return num; // Return final single-digit number
    }
};
