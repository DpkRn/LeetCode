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