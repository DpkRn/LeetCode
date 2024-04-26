class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<int> dp(26,0);
        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<26;j++){
                if(abs(s[i]-(j+'a'))<=k)
                maxi=max(dp[j],maxi);                
            }
            dp[s[i]-'a']=1+maxi;
        }       
        //for(auto it:dp) cout<<it<<" ";
        return *max_element(dp.begin(),dp.end());  
    }
};
/*class Solution {
public:
    int solve(int i,char last,string &s,int k,auto &dp){
        if(i>=s.size()) return 0;
        if(dp[i][last-'a']!=-1) return dp[i][last-'a'];
        int pick=-1e9;
        if(last=='{'||abs(s[i]-last)<=k)
            pick=1+solve(i+1,s[i],s,k,dp);
           int notpick=solve(i+1,last,s,k,dp);
        return dp[i][last-'a']=max(pick,notpick);
    }
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(27,-1));
        return solve(0,'{',s,k,dp);
    }
};
*/