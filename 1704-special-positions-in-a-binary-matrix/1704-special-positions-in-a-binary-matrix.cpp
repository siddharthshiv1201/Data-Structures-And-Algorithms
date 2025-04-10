class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0) return 0;
        int n = mat[0].size();
        
        vector<int> rowCount(m, 0);  // Count of 1s in each row
        vector<int> colCount(n, 0);  // Count of 1s in each column
        
        // First pass: count 1s in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        // Second pass: check for special positions
        int special = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    special++;
                }
            }
        }
        
        return special;
    }
};