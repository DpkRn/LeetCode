class Solution {
public:
    int f(int i,int j,auto &nums,auto &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=-1e9;
        for(int k=i;k<=j;k++){
           
            int coins=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            maxi=max(coins,maxi);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        int c=n-2;
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return f(1,c,nums,dp);
    }
};
/*

class Solution {
public:
    int f(int i,int j,auto &nums,auto &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=-1e9;
        for(int k=i;k<=j;k++){
            int left=i-1>=0?nums[i-1]:1;
            int right=j+1<nums.size()?nums[j+1]:1;
            int coins=left*nums[k]*right+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            maxi=max(coins,maxi);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,n-1,nums,dp);
    }
};

*/