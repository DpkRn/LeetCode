class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+nums[i-1];
        }
        
        for(int i=0;i<=n;i++){
           // dp[i]=dp[i]<0?(dp[i]%k+k)%k:dp[i]%k; //
            dp[i]=(dp[i]%k+k)%k; //+k is for positive reminder
           
        }
        cout<<endl;
        int cnt=0;
        unordered_map<int,int> mp;
        for(int i=0;i<=n;i++){
            cnt+=mp[dp[i]];
            mp[dp[i]]++;
        }
        return cnt;
    }
};