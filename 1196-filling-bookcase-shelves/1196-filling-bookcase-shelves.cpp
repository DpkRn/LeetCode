class Solution {
public:
    int solve(int n,auto &books,int s,auto &dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int currWidth=s;
        int maxHeight=0;
        int ans=1e9;
        for(int i=n;i>=0;i--){
            int width=books[i][0];
            int height=books[i][1];
            if(currWidth<width) break;
                currWidth-=width;
                maxHeight=max(height,maxHeight);
                ans=min(ans,maxHeight+solve(i-1,books,s,dp));
        }
        return dp[n]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> dp(n,-1);
        return solve(n-1,books,shelfWidth,dp);
    }
};