class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int freq[60] = {0};
        int result = 0;
        for (int i : time){
            // look at the 0 frequency if 60 divides i
            result += freq[60 * (i % 60 != 0) - (i % 60)];
            freq[i % 60]++;
        }
        return result;
    }
};