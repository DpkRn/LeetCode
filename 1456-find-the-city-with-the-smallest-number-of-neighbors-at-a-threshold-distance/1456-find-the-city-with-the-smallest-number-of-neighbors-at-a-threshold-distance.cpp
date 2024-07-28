class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        vector<int> mp(n);
        for(auto it:edges){
            dp[it[0]][it[1]]=it[2];
            dp[it[1]][it[0]]=it[2];
        }
       
       
         for(int i=0;i<n;i++){
            dp[i][i]=0;
            mp[i]=i;
          
        }
        vector<int> cnt(n,0);
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[i][k]!=1e9&&dp[k][j]!=1e9&&(dp[i][j]>dp[i][k]+dp[k][j])){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
            if(i!=j&&dp[i][j]<=distanceThreshold)
            cnt[i]++;
            cout<<dp[i][j]<<" ";
           }
           cout<<endl;
        }
          
        sort(mp.begin(),mp.end(),[&](int a,int b){
            if(cnt[a]!=cnt[b]) return cnt[a]<cnt[b];
            else return a>b;
        });
         
        return mp[0];
    }
};