class Solution {
public:
    int maxVowels(string s, int k) {
        list<char> ll;
        int i = 0, j = 0, count = 0, maxCount = 0;

        while (j < s.size()) {
            ll.push_back(s[j]);

            if (ll.back() == 'a' || ll.back() == 'e' || ll.back() == 'i' ||
                ll.back() == 'o' || ll.back() == 'u') {
                count++;
            }

            if (j - i + 1 > k) {
                if (ll.front() == 'a' || ll.front() == 'e' ||
                    ll.front() == 'i' || ll.front() == 'o' ||
                    ll.front() == 'u') {
                    count--;
                }
                ll.pop_front();
                i++;
            }

            maxCount = max(maxCount, count);
            j++;
        }
        return maxCount;
    }
};
