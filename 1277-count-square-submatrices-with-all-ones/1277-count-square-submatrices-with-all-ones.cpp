class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++) dp[i][0]=matrix[i][0];
        for(int i=0;i<m;i++) dp[0][i]=matrix[0][i];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]){
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        int sum=0;
        for(int i=0;i<m*n;i++){
            sum+=dp[i/m][i%m];
        }
        return sum;
    }
};