class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi=1;
        
        for(int curr=0;curr < n;curr++){
            for(int prev=0;prev < curr;prev++){
                if(nums[prev] < nums[curr]){
                    if(1+dp[prev]>dp[curr]){
                        dp[curr]=1+dp[prev];
                        cnt[curr]=cnt[prev];
                    }else if(1+dp[prev]==dp[curr]){
                        cnt[curr]+=cnt[prev];
                    }
                }                    
            }
            maxi=max(dp[curr],maxi);
        }
        int ans=0;
        for(int i=0;i < n;i++) {
           if(maxi==dp[i])
               ans=ans+cnt[i];
        }
        return ans;
    }
};