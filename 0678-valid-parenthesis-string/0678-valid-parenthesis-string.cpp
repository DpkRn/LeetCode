class Solution
{ vector<vector<int>> dp;
    public:
        bool fun(int i, int cnt, string &s)
        {
            if (i == s.size())
            {
                if (cnt == 0)
                {
                    return 1;
                }else return 0;
            }
            if(dp[i][cnt]!=-1) return dp[i][cnt];
            bool ans=false;
            if(s[i]=='('||s[i]=='*'){
                ans=ans||fun(i+1,cnt+1,s);
            }
            if(s[i]=='*'){
                 ans=ans||fun(i+1,cnt,s);
            }
            if(s[i]==')'||s[i]=='*'){
                if(cnt>0)
                ans=ans||fun(i+1,cnt-1,s);
                else return dp[i][cnt]=ans||false;
            }
            return dp[i][cnt]=ans;
        }
    bool checkValidString(string s)
    {
        int cnt = 0;
        int n=s.size();
        dp=vector<vector<int>> (n+1,vector<int>(n+1,-1));
        return fun(0, cnt, s);
        
    }
};