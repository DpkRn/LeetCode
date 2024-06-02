class Solution {
public:
    vector<int> LPS(string p){
        int n=p.size();
        vector<int> lps(n,0);
        int i=1,len=0;
        while(i<n){
            if(p[i]==p[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len>0){
                    len=lps[len-1];
                    continue;
                }
                i++;
            }
        }
        return lps;
    }
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        vector<int> lps=LPS(word);
        int maxi=lps[n-1];
        while(maxi>0&&(n-maxi)%k!=0)
            maxi=lps[maxi-1];
        return (n-maxi)%k==0?(n-maxi)/k:(n+k-1)/k;
    }
};