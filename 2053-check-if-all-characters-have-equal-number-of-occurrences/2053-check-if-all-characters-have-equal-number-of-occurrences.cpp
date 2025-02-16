class Solution {
public:
    bool areOccurrencesEqual(string s) {
        sort(s.begin(),s.end());
        unordered_map<char,int> map1;
        for(int i=0; i<s.size(); i++){
            map1[s[i]]++;
        }
         unordered_set<int> freqSet;
    for (auto& pair : map1) {
        freqSet.insert(pair.second);
    }
     if(freqSet.size()==1){
        return true;
     }   
     return false;
    }
};