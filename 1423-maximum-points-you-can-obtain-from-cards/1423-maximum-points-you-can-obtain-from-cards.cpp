class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lSum=0,rSum=0,tSum=0;
        for(int i=0;i<k;i++){
            lSum+=cardPoints[i];
        }
        tSum=lSum;
        int l=k-1,r=n-1;
        while(l>=0){
            lSum-=cardPoints[l--];
            rSum+=cardPoints[r--];
            tSum=max(tSum,lSum+rSum);
        }
        return tSum;
    }
};

/*
MLE
class Solution {
public:
     int solve(int l,int r,auto &cardPoints,int k,auto &dp){
        if(r<l||k==0){
            return 0;
        }
         if(dp[l][r][k]!=-1) return dp[l][r][k];
        int pickLeft=cardPoints[l]+solve(l+1,r,cardPoints,k-1,dp);
        int pickRight=cardPoints[r]+solve(l,r-1,cardPoints,k-1,dp);
        return dp[l][r][k]=max(pickLeft,pickRight);
    }
    int maxScore(vector<int>& cardPoints, int k) {
         int n=cardPoints.size();
         vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        
         return solve(0,n-1,cardPoints,k,dp);
    }
};
*/
/*
TLE
class Solution {
public:
    int solve(int l,int r,auto &cardPoints,int k){
        if(r<l||k==0){
            return 0;
        }
        int pickLeft=cardPoints[l]+solve(l+1,r,cardPoints,k-1);
        int pickRight=cardPoints[r]+solve(l,r-1,cardPoints,k-1);
        return max(pickLeft,pickRight);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        return solve(0,n-1,cardPoints,k);
    }
};
*/