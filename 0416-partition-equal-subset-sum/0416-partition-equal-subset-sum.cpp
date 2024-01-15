class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum&1)==1) return false;
        int n=nums.size();
        int k=sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=k)
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                bool pick=false;
                if(nums[i]<=j) pick=dp[i-1][j-nums[i]];
                bool notpick=dp[i-1][j];
                dp[i][j]=pick or notpick;
            }
        }
        return dp[n-1][k];
    }
};

/*
class Solution {
public:
    bool f(int n,int k,auto &nums,auto &dp){
        if(k==0) return true;
        if(n==0) return nums[n]==k;
        //pick condition
        if(dp[n][k]!=-1) return dp[n][k];
        bool pick=nums[n]<=k?f(n-1,k-nums[n],nums,dp):false;
        bool notpick=f(n-1,k,nums,dp);
        return dp[n][k]=pick or notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum&1)==1) return false;
        int n=nums.size();
        int k=sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1,k,nums,dp);        
    }
    
};

*/