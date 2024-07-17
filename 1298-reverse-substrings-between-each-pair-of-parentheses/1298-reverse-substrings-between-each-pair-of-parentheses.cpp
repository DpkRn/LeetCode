class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string rev;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else if(s[i]==')'){
                int k=st.top();
                reverse(s.begin()+k+1,s.begin()+i);
                st.pop();
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')'){
                    rev+=s[i];
            }
        }

        return rev;
    }
};