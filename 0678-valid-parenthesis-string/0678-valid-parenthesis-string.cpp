class Solution
{ //vector<vector<int>> dp;
    public:
//         bool fun(int i, int cnt, string &s)
//         {
//             if (i == s.size())
//             return cnt==0;
            
//             if(dp[i][cnt]!=-1) return dp[i][cnt];
            
//             bool ans=false;
            
//             if(s[i]=='('||s[i]=='*'){
//                 ans=ans||fun(i+1,cnt+1,s);
//             }
            
//             if(s[i]=='*'){
//                  ans=ans||fun(i+1,cnt,s);
//             }
            
//             if(s[i]==')'||s[i]=='*'){
//                 if(cnt>0)
//                 ans=ans||fun(i+1,cnt-1,s);
//                 else return dp[i][cnt]=ans||false;
//             }
            
//             return dp[i][cnt]=ans;
//         }
    bool checkValidString(string s)
    {
      //  int cnt = 0;
        int n=s.size();
        // dp=vector<vector<int>> (n+1,vector<int>(n+1,-1));
        // return fun(0, cnt, s);
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
            
                if(s[i]=='('||s[i]=='*'){
                    dp[i][j]=dp[i][j]||dp[i+1][j+1];
                }
                    
                if(s[i]=='*'){
                     dp[i][j]=dp[i][j]||dp[i+1][j];
                }

                if(s[i]==')'||s[i]=='*'){
                    if(j>0)
                    dp[i][j]=dp[i][j]||dp[i+1][j-1];
                    else dp[i][j]=dp[i][j]||false;
                }
            }
        }
       
        // for(auto it:dp){
        //     for(auto el:it) cout<<el<<" "; cout<<endl; 
        // }
        return dp[0][0];
    }
};