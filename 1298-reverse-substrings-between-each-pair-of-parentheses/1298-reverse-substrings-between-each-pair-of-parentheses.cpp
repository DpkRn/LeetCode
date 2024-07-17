class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string rev;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i+1);
            else if(s[i]==')'){
                int k=st.top();
                for(int j=0;j<((i-1)-k+1)/2;j++){
                    swap(s[j+k],s[i-1-j]);
                }
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