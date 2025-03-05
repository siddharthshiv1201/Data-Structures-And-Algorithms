class Solution {
public:
    int factorial(int n) {  
        if (n == 0 || n == 1) return 1;
        return n * factorial(n - 1); 
    }
    int trailingZeroes(int n) {
         int count = 0;
        while (n > 0) {
            count += n / 5;  
            n /= 5;
        }
        return count;
        
    }
};