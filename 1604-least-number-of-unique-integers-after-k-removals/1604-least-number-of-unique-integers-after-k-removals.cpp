class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> map1;
        for(int i=0; i<arr.size(); i++){
            map1[arr[i]]++;
        }
        vector<int> freq;
        for(const auto& pair: map1){
            freq.push_back(pair.second);
        }

        sort(freq.begin(),freq.end());
        int count=freq.size();

        for(int i=0 ;i<freq.size(); i++){
            if(k>=freq[i]){
                k-=freq[i];
                count--;
            }
            else{
                break;
            }
        }
        return count;
        
    }
};