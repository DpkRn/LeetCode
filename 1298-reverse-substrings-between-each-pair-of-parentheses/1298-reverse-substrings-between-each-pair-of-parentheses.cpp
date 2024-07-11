class Solution {
public:
    string reverseParentheses(string s) {
     stack<char> st;
     int n=s.size();
     for(int i=0;i<n;i++){
        if(s[i]==(')')){
            string str="";
            while(!st.empty()&&st.top()!=('(')){
                str.push_back(st.top());
                st.pop();
            }
           // reverse(str.begin(),str.end());
            if(!st.empty()&&st.top()==('(')) st.pop();
            int h=str.size();
            for(int j=0;j<h;j++) st.push(str[j]);
        } else st.push(s[i]);
     }
      string ans="";
      while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};