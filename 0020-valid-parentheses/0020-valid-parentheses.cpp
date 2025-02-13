class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.size()==0) return false;
                char top=st.top();
                if((s[i] == ')' && top == '(') || 
                (s[i] == '}' && top == '{') || 
                (s[i] == ']' && top == '[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.size()==0) return true;
        else{
            return false;
        }
        
    }
};