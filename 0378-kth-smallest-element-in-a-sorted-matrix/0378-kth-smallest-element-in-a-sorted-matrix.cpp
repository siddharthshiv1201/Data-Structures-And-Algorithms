class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> v;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                v.push_back(matrix[i][j]);
            }
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }
};