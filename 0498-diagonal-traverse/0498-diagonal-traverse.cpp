class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans(n*m);
        for (int i = 0, idx = 0; i < n + m - 1; i++) {
            if (i % 2) {
                for (int y = min(i, m - 1), x = i - y; y >= 0 && x < n; x++, y--)
                    ans[idx++] = matrix[x][y];
            } else {
                for (int x = min(i, n - 1), y = i - x; x >= 0 && y < m; y++, x--)
                    ans[idx++] = matrix[x][y];
            }
        }
        return ans;
    }
};