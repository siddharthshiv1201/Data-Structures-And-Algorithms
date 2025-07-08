class Solution {
public:
    string resultingString(string s) {
        stack<char>q;

        for(int i=0 ; i<s.length() ; i++){
            if(!q.empty()){
                if(q.top() - s[i] == 1 || s[i] - q.top() == 1 ){
                    q.pop();
                }
                else if(q.top() == 'z' && s[i] == 'a' || q.top() == 'a' && s[i] == 'z'){
                    q.pop();
                }
                else{
                    q.push(s[i]);
                }
            }
            else{
                q.push(s[i]);
            }
        }

        string ans = "";

        while(!q.empty()){
            ans += q.top();
            q.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};