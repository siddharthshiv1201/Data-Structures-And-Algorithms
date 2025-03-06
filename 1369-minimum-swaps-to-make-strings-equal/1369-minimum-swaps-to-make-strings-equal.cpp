class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1.length() != s2.length()) return -1;
        int x1 = 0, y1 = 0; // count the differences by the litter of s1
        for(int i  = 0; i < s1.length(); i++) {
            if(s1[i] == s2[i]) continue;
            else {
                if(s1[i] == 'x') x1++;
                else y1++;
            }
        }
        if((x1+y1)%2) return -1; // can not fix an odd number of differences
        // for same type diffs we can fix two with one swap
        // so tackle that first then return the rest
        return x1/2 + y1/2 + x1%2 + y1%2;
    }
};