class Solution {
public:
    int balancedString(string s) {
        map<char,int> mp;
        for(int i = 0;i < s.length();i++) {
            mp[s[i]]++;
        }

        int left = 0;
        int ans = INT_MAX;
        int x = s.length()/4;

        for(int right = 0;right < s.length();right++) {
            mp[s[right]]--;
            while(left < s.length() && mp['Q'] <= x && mp['W'] <= x && mp['E'] <= x && mp['R'] <= x) {
                mp[s[left]]++;
                ans = min(ans,right - left + 1);
                left++;
            }
        }
        return ans;
    }
};