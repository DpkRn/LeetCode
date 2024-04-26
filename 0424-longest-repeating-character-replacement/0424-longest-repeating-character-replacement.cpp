class Solution {
public:
    int characterReplacement(string s, int k) {
            int n = s.size();
            int maxLen = 0,l=0,maxi=0;          
            int hash[26]={0};
        for (int i = 0; i < n; i++){
              hash[s[i]-'A']++;
              maxi=max(maxi,hash[s[i]-'A']);
              while((i-l+1-maxi)>k){
                  hash[s[l]-'A']--;
                  maxi=0;
                  for(int j=0;j<26;j++){
                      maxi=max(maxi,hash[j]);
                  }
                  l++;
              }
            if(i-l+1-maxi<=k)
             maxLen=max(maxLen,i-l+1);   
        }
    return maxLen;
    }
};
/*
class Solution
{
    public:
        int characterReplacement(string s, int k)
        {
            int n = s.size();
            int maxLen = 0;
            for (int i = 0; i < n; i++)
            {
                int hash[26]={0};
                int maxi = 0;
                for (int j = i; j < n; j++)
                {
                    hash[s[j] - 'A']++;
                    maxi = max(maxi, hash[s[j] - 'A']);
                    int change = (j - i + 1 - maxi);
                   // cout<<maxi<<" "<<change<<j-i+1<<endl;
                    if (change <= k)
                        maxLen = max(maxLen, j - i + 1);
                    else break;
                }
            }
            return maxLen;
        }
};
*/