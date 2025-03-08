class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0, j = 0, cnt = 0, mini = INT_MAX;

        while (j < blocks.size()) {
            if (blocks[j] == 'W') cnt++;  

            if (j - i + 1 == k) { 
                mini = min(mini, cnt);
                if (blocks[i] == 'W') cnt--; 
                i++;
            }
            j++;
        }

        return mini;
    }
};
