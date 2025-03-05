class Solution {
public:
    long long coloredCells(int n) {
        long long c=n;
        return ((c*c)+((c-1)*(c-1)));
        
    }
};