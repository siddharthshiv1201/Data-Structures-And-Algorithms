class Solution {
public:
    vector<int> findMissing(vector<int>& a, vector<int>& b) {
        unordered_set<int> setB(b.begin(), b.end());
        vector<int> result;

        for (int num : a) {
            if (setB.find(num) == setB.end()) {
                result.push_back(num);
            }
        }

        return result;
    }
};
