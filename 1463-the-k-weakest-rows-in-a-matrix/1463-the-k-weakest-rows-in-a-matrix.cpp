class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rowStrength; // {count of 1s, row index}
        
        // Step 1: Count 1s and store with row index
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) 
                    count++;
                else 
                    break; // Since rows are sorted, we can stop early
            }
            rowStrength.push_back({count, i});
        }

        // Step 2: Sort based on count of 1s, if equal then based on index
        sort(rowStrength.begin(), rowStrength.end());

        // Step 3: Extract the first k row indices
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(rowStrength[i].second);
        }

        return result;
    }
};
