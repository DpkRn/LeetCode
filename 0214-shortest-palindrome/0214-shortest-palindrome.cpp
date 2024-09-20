class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        long long prefix=0,suffix=0;
        int last_ind=-1;
        long long base=29,pow=1,mod=1e9+7;
        for(int i=0;i<n;i++){
            int ch=s[i]-'a'+1;
            prefix=(prefix*base+ch)%mod;
            suffix=(ch*pow+suffix)%mod;
            pow=(pow*base)%mod;
            if(prefix==suffix) last_ind=i;
        }
        string preStr;
        for(int j=n-1;j>last_ind;j--) preStr.push_back(s[j]);
        return preStr+s;
    }
};