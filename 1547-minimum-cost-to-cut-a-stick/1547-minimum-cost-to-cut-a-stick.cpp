class Solution {
public:
    // int f(int i,int j,auto &cuts,auto &dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int mini=1e9;
    //     for(int k=i;k<=j;k++){
    //             int cost=cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
    //             mini=min(cost,mini);                           
    //     }
    //     return dp[i][j]=mini;
    // }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);   
        sort(cuts.begin(),cuts.end());
        int s=cuts.size();
//         vector<vector<int>> dp(s-1,vector<int> (s-1,-1));
//         return f(1,s-2,cuts,dp)   ;
        int c=s-2; //size of original cuts array
        
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                 if(i>j) continue;
                int mini=1e9;
                 for(int k=i;k<=j;k++){
                    
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(cost,mini);                           
                  }
              dp[i][j]=mini;
            }
        }
        return dp[1][s-2];
    }
};