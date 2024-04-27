class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(int ind,int ptr,string ring,string key){
    //     int n=ring.size();
    //     //base case
    //     if(ind>=key.size()) return 0;
    //     if(dp[ind][ptr]!=-1) return dp[ind][ptr];
    //     int steps=1e9;
    //     for(int i=0;i<n;i++){
    //         if(ring[i]==key[ind]){
    //             steps=min(steps,min(abs(ptr-i),n-abs(ptr-i))+1+solve(ind+1,i,ring,key));
    //         }
    //     }
    //  return dp[ind][ptr]=steps;
    // }
    int findRotateSteps(string ring, string key) {
        int ptr=0;//ring ptr
        int ind=0;//key ptr
        int n=ring.size();
        int m=key.size();
        // dp.assign(m,vector<int>(n,-1));
        // return solve(ind,ptr,ring,key);
        
        vector<vector<int>> dp(m+1,vector<int>(n,0));
        for(int ind=m-1;ind>=0;ind--){
            for(int ptr=n-1;ptr>=0;ptr--){
                int steps=1e9;
                for(int i=0;i<n;i++){
                    if(ring[i]==key[ind]){
                        steps=min(steps,min(abs(ptr-i),n-abs(ptr-i))+1+dp[ind+1][i]);
                     } 
                }
                dp[ind][ptr]=steps;
                
            }
        }
        return dp[0][0];
        
    }
};
/*
class Solution {
public:
    int fun(int k,int r,string key,string ring,auto &dp){
       if(k>=key.size()) return 0;
        if(dp[k][r]!=-1) return dp[k][r];
        int clock=0;
        for(int i=r;;i++){
            if(i==ring.size()) i=0;
            if(key[k]==ring[i]){
               clock+=(1+fun(k+1,i,key,ring,dp));
               break;
            }
            clock++;
        }
        int anti=0;
        for(int i=r;;i--){
            if(i==-1) i=ring.size()-1;
            if(ring[i]==key[k]){
                anti+=(1+fun(k+1,i,key,ring,dp));
                break;
            }
            anti++;
        }
        return dp[k][r]=min(anti,clock);     
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size();
        int k=key.size();
        
        vector<vector<int>> dp(k,vector<int>(n,-1));
        return fun(0,0,key,ring,dp);
    }
};
*/