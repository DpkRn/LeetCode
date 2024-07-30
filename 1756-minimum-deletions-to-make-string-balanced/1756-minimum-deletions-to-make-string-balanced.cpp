class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int bCnt=0,aCnt=0;vector<int> b(n),a(n);
        for(int i=0;i<n;i++){
           b[i]=bCnt;
           if(s[i]=='b') bCnt++;
           a[n-1-i]=aCnt;
           if(s[n-i-1]=='a') aCnt++;
        }
        int ans=1e9;
       for(int i=0;i<n;i++){
            ans=min(ans,a[i]+b[i]);
       }
       return ans;
    }
};