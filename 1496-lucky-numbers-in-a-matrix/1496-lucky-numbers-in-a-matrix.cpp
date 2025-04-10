class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int> rows(m);
        vector<int> cols(n);

        // mIN of the row
        
        for(int i=0; i<m; i++){
            int mini=INT_MAX;
            for(int j=0; j<n; j++){
                mini=min(mini,matrix[i][j]);
            }
            rows[i]=mini;
        }

        // max of the row

        for(int j=0; j<n; j++){
            int maxi=INT_MIN;
            for(int i=0; i<m; i++){
                maxi=max(maxi,matrix[i][j]);
            }
            cols[j]=maxi;
        }
        vector<int> result;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==rows[i] && matrix[i][j]==cols[j]){
                    result.push_back(matrix[i][j]);

                }
            }
        }
        return result;
        
    }
};