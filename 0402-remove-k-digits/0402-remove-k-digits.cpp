class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(auto &ch:num){
            while(!st.empty()&&st.top()>ch&&k>0){
                st.pop();
                k--;
            }
            if(st.empty()&&ch=='0') continue; 
            st.push(ch);
        }
        while(!st.empty()&&k>0){
            st.pop();
            k--;
        }
        string ans=st.empty()?"0":"";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};