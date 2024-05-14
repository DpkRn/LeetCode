class Solution {
public:
    bool isValid(int i,int j,auto &prefix){
        int cnt=0;
        bool flag=true;
        for(int k=0;k<26;k++){
            int freq=prefix[j][k]-(i-1>=0?prefix[i-1][k]:0);
            if(cnt!=0&&freq!=0&&cnt!=freq) flag=false;
            cnt=max(cnt,freq);
        }
        return flag;
    }
    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        
        vector<vector<int>> prefix(n,vector<int>(26,0));
        vector<int> hash(26,0);
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
            prefix[i]=hash;
        }
        
        vector<int> dp(n+1,n);
        dp[0]=1;
        
        for(int i=1;i<n;i++){
            for(int j=i;j>=0;j--){
                if(isValid(j,i,prefix)){
                    
                    if(j==0) dp[i]=1;
                    else
                    dp[i]=min(dp[i],1+dp[j-1]);
                }
            }
        }
        return dp[n-1];
    }
};