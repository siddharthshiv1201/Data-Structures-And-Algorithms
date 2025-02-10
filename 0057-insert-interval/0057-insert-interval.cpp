class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>> v1;
        for(int i=0; i<intervals.size(); i++){
            v1.push_back(intervals[i]);
        }
        v1.push_back(newInterval);
        sort(v1.begin(),v1.end());
        vector<vector<int>> my;
        my.push_back(v1[0]);
        for(int i=0; i<v1.size(); i++){
            if(my.back()[1]>=v1[i][0]){
                my.back()[1]=max(my.back()[1],v1[i][1]);
            }
            else{
                my.push_back(v1[i]);
            }
        }
        return my;
        
        
    }
};