class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=string::npos)
        {
             s.erase(s.find(part),part.length());
        }
        return s;
    }
};