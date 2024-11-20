class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<string> ans;
        
        vector<vector<int>> dp(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(auto it:words[i]){
                dp[i][it-'a']++;
            }
        }

        for(int i=0;i<26;i++){
            int mini=1e9;
            for(int j=0;j<n;j++){
                mini=min(mini,dp[j][i]);
            }
            char ch='a'+i;
            for(int i=0;i<mini;i++)
            ans.push_back(string(1, ch));
        }
        return ans;
    }
};