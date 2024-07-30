class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int ps[2][n+1];
    
        ps[0][0]=0;
        ps[1][0]=0;
        for(int i=0;i<n;++i){
           ps[0][i+1]=ps[0][i]+(s[i]=='a');
           ps[1][i+1]=ps[1][i]+(s[i]=='b');
        }
        
       int ans=1e9;
       for(int i=0;i<=n;++i){
            int left=ps[1][i];
            int right=ps[0][n]-ps[0][i];
            ans=min(ans,left+right);
       }
       return ans;
    }
};