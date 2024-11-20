class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int> st;
       
        for(int i=0;i<n;i++){
             int val=0;
            if(s[i]=='('){ //push 0 so that at the time of adding internal value we can check opening bracket limit
                st.push(0);
            }else{
                //calculate all the internal calculation
                while(st.top()!=0){
                    val+=st.top();
                    st.pop();
                }
                //add and replace the bracket value
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