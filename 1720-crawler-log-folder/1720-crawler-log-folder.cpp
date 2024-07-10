class Solution {
public:
    int minOperations(vector<string>& logs) {
       int n=logs.size();
       stack<string> st;
      for(int i=0;i<n;i++){
        if(logs[i]=="./"){
            continue;
        }else if(logs[i]=="../"){
            if(!st.empty()) st.pop();
        }else st.push(logs[i]);
       }
       return st.size();
    }
};