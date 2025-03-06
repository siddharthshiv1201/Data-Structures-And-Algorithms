class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> v;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());
        unordered_map<int, int> map1;
        vector<int> result;
        for (int i = 0; i < v.size(); i++) {
            map1[v[i]]++;
        }
        int repeated = -1, missing = -1;
        for (int i = 1; i <= v.size(); i++) {
            if (map1[i] > 1) repeated = i; 
            if (map1[i] == 0) missing = i; 
        }
        result.push_back(repeated);
        result.push_back(missing);

        return result;
    }
};
