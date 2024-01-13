class Solution {
public:
    int f(int ind,int i,vector<vector<int>>& triangle,vector<vector<int>> &dp){
        if(ind==triangle.size()) return 0;
        if(dp[ind][i]!=-1) return dp[ind][i];     
              int left=triangle[ind][i]+f(ind+1,i,triangle,dp);
              int right=triangle[ind][i]+f(ind+1,i+1,triangle,dp);
              return dp[ind][i]=min(left,right);      
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,triangle,dp);
    }
};