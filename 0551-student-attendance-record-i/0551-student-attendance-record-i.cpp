class Solution {
public:
    bool checkRecord(string s) {
        int n=s.size();
        vector<int> dp(n,0);
 
        for(auto it:dp) cout<<it<<" ";
        int cnt=1;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                dp[i]=(i==0)?(s[i]=='L'):dp[i-1]+1;
            } else{
                dp[i]=0;
            }
            if(s[i]=='A') cnt--;
            if(cnt<0||dp[i]>=3) return false;
            
        }
        return true;
    }
};