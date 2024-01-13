class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> dpprev(n,0);
        for(int i=0;i<n;i++){
            dpprev[i]=matrix[m-1][i];
        }
        
        for(int r=n-2;r>=0;r--){
            vector<int> dpcurr(n,0);
            for(int c=0;c<n;c++){
                 int left=c-1>=0?matrix[r][c]+dpprev[c-1]:INT_MAX;
                 int mid=matrix[r][c]+dpprev[c];
                 int right=c+1<=n-1?matrix[r][c]+dpprev[c+1]:INT_MAX;  
                dpcurr[c]=min(left,min(right,mid));
               
            }
             dpprev=dpcurr;
        }
        
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
            mini=min(mini,dpprev[i]);
        
        return mini;
    }
};

/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[m-1][i]=matrix[m-1][i];
        }
        
        for(int r=n-2;r>=0;r--){
            for(int c=0;c<n;c++){
                 int left=c-1>=0?matrix[r][c]+dp[r+1][c-1]:INT_MAX;
                 int mid=matrix[r][c]+dp[r+1][c];
                 int right=c+1<=n-1?matrix[r][c]+dp[r+1][c+1]:INT_MAX;  
                dp[r][c]=min(left,min(right,mid));
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
            mini=min(mini,dp[0][i]);
        return mini;
    }
};

*/
/*
class Solution {
    int f(int ind,int i,vector<vector<int>>& matrix,int m,int n,vector<vector<int>> &dp){
        if(ind==m-1) return matrix[ind][i];
        if(dp[ind][i]!=-1) return dp[ind][i];      
        int left=i-1>=0?matrix[ind][i]+f(ind+1,i-1,matrix,m,n,dp):INT_MAX;
        int mid=matrix[ind][i]+f(ind+1,i,matrix,m,n,dp);
        int right=i+1<=n-1?matrix[ind][i]+f(ind+1,i+1,matrix,m,n,dp):INT_MAX;        
        return dp[ind][i]=min(left,min(mid,right));        
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int mini=INT_MAX; 
        for(int i=0;i<n;i++)
         mini=min(mini,f(0,i,matrix,m,n,dp));     
        return mini;
    }
};
*/