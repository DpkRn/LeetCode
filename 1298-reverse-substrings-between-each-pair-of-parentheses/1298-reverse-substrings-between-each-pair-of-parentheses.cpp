class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        int n=s.size();
        vector<int> ind(n,-1);
        
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                ind[st.top()]=i;
                ind[i]=st.top();
                st.pop();
            }
        }
        string str="";
        int dir=1;
        for(int i=0;i<n;i+=dir){
            if(s[i]=='(' || s[i]==')'){
                    dir*=-1;
                    i=ind[i];
            }else str+=s[i];
        }

        return str;
    }
};


/*
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
*/