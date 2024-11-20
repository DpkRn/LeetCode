class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int> st;
       
        for(int i=0;i<n;i++){
             int val=0;
            if(s[i]=='('){
                st.push(0);
            }else{
                while(st.top()!=0){
                    val+=st.top();
                    st.pop();
                }
                val=max(2*val,1);
                st.pop();
                st.push(val);
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};