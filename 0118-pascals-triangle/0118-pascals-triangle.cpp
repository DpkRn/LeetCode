class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
        dp[i][0]=1;
            for(int i=1;i<n;i++){
                for(int j=1;j<=i;j++){
                   dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                dp[i].resize(i+1);
            }
            dp[0].resize(1);
        }
        return dp;
    }
};

//other method
/*
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp;
        
      dp.push_back({1});
        
        for(int i=1;i<n;i++){
            vector<int> temp(i+1,1);
            for(int j=1;j<i;j++){
              temp[j]= dp[i-1][j-1]+dp[i-1][j];          
            }
            dp.push_back(temp);
         }
        return dp;
    }
};
*/