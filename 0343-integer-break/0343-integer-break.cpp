class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n - 1;

        int rem = n % 3;
        int qt = n / 3;

        if(rem == 0) return pow(3, qt);
        else if(rem == 1) return pow(3, qt-1) * 4;
        else return pow(3, qt) * 2;
       
    }
};