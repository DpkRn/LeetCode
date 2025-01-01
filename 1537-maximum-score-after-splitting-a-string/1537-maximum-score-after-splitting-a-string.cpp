class Solution {
public:
    
    int maxScore(string s) {
        int n=s.size();
        int ones=0,zeros=0;
        int ans=0;

        for(int i=0;i<n;i++){
            ones+=(s[i]=='1');         
        }
        
        for(int i=0;i<n-1;i++){
            zeros+=(s[i]=='0'); 
            ones-=(s[i]=='1');     
            ans=max(ans,ones+zeros);
        }
      
        
        return ans;       
    }
};