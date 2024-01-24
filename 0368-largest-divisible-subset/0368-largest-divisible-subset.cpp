class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        int maxi=1;
        int lastInd=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0&&1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                lastInd=i;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd){
            lastInd=hash[lastInd];
            ans.push_back(nums[lastInd]);
        }
        return ans;
      
    }
};