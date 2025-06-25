class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (char ch : s) {
            if (!st.empty() && st.top().first == ch) {
                st.top().second++;  // increment freq
                if (st.top().second == k) {
                    st.pop();  // remove when freq reaches k
                }
            } else {
                st.push({ch, 1});  // new char with freq 1
            }
        }

        // Step 4: Build result string
        string result = "";
        while (!st.empty()) {
            auto [ch, freq] = st.top();
            result.append(freq, ch);  // append char freq times
            st.pop();
        }

        // Step 5: reverse result
        reverse(result.begin(), result.end());
        return result;
    }
};
