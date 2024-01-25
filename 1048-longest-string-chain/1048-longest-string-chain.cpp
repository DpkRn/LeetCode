class Solution {
    bool isChain(string s,string t){
      //bdc bdac
        int cnt=0;
        int l=0;
        if(t.size()<=s.size()) return false;
        if(t.size()-s.size()>=2) return false;
      for(int i=0;i<t.size();i++){          
          if(s[l]==t[i]) l++;
          else {
            cnt++;
          }
        if(cnt>=2) return false;
      }
        return true;
    }
    static bool com(string s1,string s2){
     return s1.size()<s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),com);
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(isChain(words[prev],words[i])&&(1+dp[prev]>dp[i]))
                    dp[i]=1+dp[prev];
            }
            if(maxi<dp[i])
                maxi=dp[i];
        }
        return maxi;
    }
};