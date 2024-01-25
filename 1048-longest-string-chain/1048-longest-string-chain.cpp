class Solution {
    bool isChain(string s,string t){
        //s=bbab t=abc
      if(s.size()!=t.size()+1) return false;
        int first=0;
        int second=0;
        while(first<s.size()){
            if(s[first]==t[second]){
                first++; second++;
            }else{
                first++;
            }
            
        }
        if(first==s.size()&&second==t.size()) return true; return false;
        
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
                if(isChain(words[i],words[prev])&&(1+dp[prev]>dp[i]))
                    dp[i]=1+dp[prev];
            }
            if(maxi<dp[i])
                maxi=dp[i];
        }
        return maxi;
    }
};