class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;
        long long dp[zero + 1][one + 1][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        for(int i = 1; i <= zero; i++){
            if(i <= limit) dp[i][0][0] = 1; 
        }
        for(int i = 1; i <= one; i++){
            if(i <= limit) dp[0][i][1] = 1;
        }
        for(int i = 1; i <= zero; i++){
            for(int j = 1; j <= one; j++){
                int k = i - 1;
                while(k >= 0 && i - k <= limit){
                    dp[i][j][0] += dp[k][j][1];
                    dp[i][j][0] %= mod;
                    k--;
                }
                k = j - 1;
                while(k >= 0 && j - k <= limit){
                    dp[i][j][1] += dp[i][k][0];
                    dp[i][j][1] %= mod;
                    k--;
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};
// zero + one
