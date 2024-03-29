class Solution {
public:  
    bool isPalindrome ( int i, int j,string & s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    // int f(int n,string &s,auto &dp){
    //     if(n==0||isPalindrome(0,n,s)) return 0;
    //     if(dp[n]!=-1) return dp[n];
    //     int mini=INT_MAX;
    //     for(int i=0;i<=n;i++){
    //         if(isPalindrome(i,n,s)){
    //             int cnt=1+f(i-1,s,dp);
    //             mini=min(cnt,mini);
    //         }
    //     }
    //     return dp[n]=mini;
    // }
    int minCut(string s) {
        int n=s.size();
        // vector<int> dp(n+1,-1);
        // return f(n-1,s,dp);
        
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++){
            if(isPalindrome(0,i,s)) {continue; }
            int mini=INT_MAX;
            for(int j=1;j<=i;j++){
                if(isPalindrome(j,i,s)){
                    int cnt=1+dp[j-1];
                    mini=min(cnt,mini);
                }
            } 
            dp[i]=mini;
        }
        return dp[n-1];        
    }
};