class Solution {
public:
    int climbStairs(int n) {
     int dp[n+1];
        dp[0]=1; dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
/*
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1; //push dp techniqe //send your way on the posible places and tell them i have some way  
        for(int i=0;i<=n;i++){
            if(i+1<=n) dp[i+1]+=dp[i];
            if(i+2<=n) dp[i+2]+=dp[i];
        }
        return dp[n];
        
    }
};

*/

/*
class Solution {
public:
    int f(int n,int k,vector<int>&dp){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int allWay=0;
        for(int i=1;i<=k;i++){
            if(n-i>=0)
                allWay+=f(n-i,k,dp);
        }
        return dp[n]=allWay;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,2,dp);
    }
};
*/

/*
class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1,0);
       // dp[0]=1;
        int prev1=1,prev2=0;
        for(int i=1;i<=n;i++){
            int prev1=prev2;
            int prev2=0;
            if(i-2>=0)
               prev2=dp[i-2];
            dp[i]=left+right;
        }
        
        return dp[n];
    }
};
/*


/*
O(N) O(N)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int left=dp[i-1];
            int right=0;
            if(i-2>=0)
               right=dp[i-2];
            dp[i]=left+right;
        }
        
        return dp[n];
    }
};
*/


/*
O(N) O(1)
class Solution {
public:
    int climbStairs(int n) {
        int prev1=1,prev2=0;
        for(int i=1;i<=n;i++){
             int curr=prev1+prev2;
            prev1=curr;
            prev2=prev1;         
        }
        return prev1;
        
    }
};
*/




/*

O(N)  O((vector)N+(stack)N)

class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n==0) return 1; //from 0 to 0 one way
        if(dp[n]!=-1) return dp[n];
        int left=solve(n-1,dp);
        int right=0;
        if(n-2>=0)   //if its going beyond 0 that means this is unvalid move so dont count.
            right=solve(n-2,dp);
        return dp[n]=left+right;
        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);   
        
    }
};

*/

 
       



