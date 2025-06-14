class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        vector<pair<int,int>> my;
        for(int i=0; i<n; i++){
            my.push_back({end[i],start[i]});
        }
        int prev=-1;
        int cnt=0;
        sort(my.begin(),my.end());
        for(int i=0; i<n; i++){
            if(my[i].second>prev){
                cnt++;
                prev=my[i].first;
            }
        }
        return cnt;
        
        
        
    }
};