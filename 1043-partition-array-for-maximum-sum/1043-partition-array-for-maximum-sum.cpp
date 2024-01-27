class Solution {
public:
    const int mod=1e9+7;
    // int f(int i,int n,int k,auto &arr,auto &dp){
    //     if(i==n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int maxiElement=-1e9,maxi=INT_MIN;
    //     for(int ind=i;ind<min(i+k,n);ind++){
    //         maxiElement=max(maxiElement,arr[ind]);
    //         int sum=((ind-i+1)*maxiElement+f(ind+1,n,k,arr,dp))%mod;
    //         maxi=max(maxi,sum);
    //     }
    //     return dp[i]=maxi;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // vector<int> dp(n,-1);
        // return f(0,n,k,arr,dp);
        
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
             int maxiElement=-1e9,maxi=INT_MIN;
             for(int ind=i;ind<min(i+k,n);ind++){
             maxiElement=max(maxiElement,arr[ind]);
             int sum=((ind-i+1)*maxiElement+dp[ind+1])%mod;
             maxi=max(maxi,sum);
        }
        dp[i]=maxi;
        }
        return dp[0];
    }
};