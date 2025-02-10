class Solution {
public:
    static bool comparator(string &a, string &b) {
        return (a + b) > (b + a);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> s1;
        for(int i = 0; i < nums.size(); i++) {
            s1.push_back(to_string(nums[i]));
        }

        // Use Solution::comparator
        sort(s1.begin(), s1.end(), comparator);

        if(s1[0] == "0"){
            return "0";
        }
        string r = "";
        for(int i = 0; i < s1.size(); i++) {
            r = r + s1[i];
        }
        return r;
    }
};
