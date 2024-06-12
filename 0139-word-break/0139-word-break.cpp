class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto &str:wordDict) st.insert(str);
        int n=s.size();
        vector<bool> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]==1&&st.find(s.substr(j,i-j))!=st.end()){
                    dp[i]=true;
                }
            }
        }
        
        return dp[n];
    }
};
/*
//brute force
class Solution {
public:
    bool dfs(int i,string s,unordered_set<string> &st){
        if(i>=s.size()) return true;
        string str="";
        for(int j=i;j<s.size();j++){
            str+=s[j];
            if(st.contains(str)&&dfs(j+1,s,st)) return true;     
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto str:wordDict) st.insert(str);
        return dfs(0,s,st);
    }
};

*/