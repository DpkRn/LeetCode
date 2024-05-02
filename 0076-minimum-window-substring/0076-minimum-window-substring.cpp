class Solution {
public:
    
    string minWindow(string s, string t) {
        int hash[256];
        int minLen=1e9;
        int sInd=-1;
        memset(hash,0,sizeof(hash));
        for(auto it:t){
            hash[it-'A']++;
        }
        int n=s.size();
        int cnt=0,l=0;
        for(int i=0;i<n;i++){
            
            if(hash[s[i]-'A']>0){
                cnt++;
            }
            hash[s[i]-'A']--;

            while(cnt==t.size()){
                if(minLen>i-l+1){
                    sInd=l;
                    minLen=i-l+1;
                }
                hash[s[l]-'A']++;
                if(hash[s[l]-'A']>0){
                    cnt--;
                }
                l++;
            }            
            
        }
        if(sInd==-1) return "";
        return s.substr(sInd,minLen);
    }
};