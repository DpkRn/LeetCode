class Solution
{
    public:
        int lengthOfLIS(vector<int> &nums)
        {
            vector<int> v;
            int n = nums.size();
            v.push_back(nums[0]);
            for (int i = 0; i < n; i++)
            {
                if (nums[i] > v.back()) v.push_back(nums[i]);
                else
                {
                    int n = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                    v[n] = nums[i];
                }
            }
            return v.size();
        }
};
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int curr=0;curr < n;curr++){
            for(int prev=0;prev < curr;prev++){
                if(nums[prev] < nums[curr])
                    dp[curr]=max(1+dp[prev],dp[curr]);
            }
        }
        int ans=0;
        for(int i=0;i < n;i++) {
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

*/
/*
class Solution {
public:
   	// int f(int ind,int prev,auto &nums,auto &dp){
   	//     if(ind==nums.size()) return 0;
   	//     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
   	//     int pick=INT_MIN;
   	//     if(prev==-1||nums[prev] < nums[ind])
   	//         pick=1+f(ind+1,ind,nums,dp);
   	//         pick=max(pick,f(ind+1,prev,nums,dp));        
   	//     return dp[ind][prev+1]=pick;     
   	// }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       	// vector<vector<int>>dp(n,vector<int> (n+1,-1));
       	// return f(0,-1,nums,dp);
        vector<vector < int>> dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=n-1;prev>=-1;prev--){
               dp[ind][prev+1]=dp[ind+1][prev+1];
                if(prev==-1||nums[ind]>nums[prev])
                    dp[ind][prev+1]=max(1+dp[ind+1][ind+1],dp[ind][prev+1]);
            }
        }
        return dp[0][0];
    }
};
*/