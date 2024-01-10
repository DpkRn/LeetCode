class Solution {
    int getAns(vector<int> dp,int n){
        for(int i=1;i<=n;i++){
            if(i-2>=0)
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        return getAns(dp,n);
        
    }
};