class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size(),cnt=0;
        vector<int> dp(n,0);
        dp[0]=arr[0];
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j;k<n;k++){
                    dp[k]=dp[k-1]^arr[k];
                    int a=dp[j-1]^dp[i]^arr[i];
                    int b=dp[k]^dp[j]^arr[j];
                    if(a==b) cnt++;
                }
            }
        }
        return cnt;
    }
};