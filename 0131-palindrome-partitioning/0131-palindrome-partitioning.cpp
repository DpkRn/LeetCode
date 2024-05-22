class Solution {
public:
    //previous submission complexity was o(2^n(2*n))
    //complexity of this code is O(2^N)
    bool isP(string str,int l,int r){
        if(l>=r) return true;
        if(str[l]!=str[r])
            return false;
        return isP(str,l+1,r-1);
    }
    void solve(int ind,string s,vector<string> &path,vector<vector<string>> &ans,vector<vector<bool>>&dp){
        if(ind>=s.size()){
            ans.push_back(path);
            return;
        }
        string str="";
        for(int i=ind;i<s.size();i++){
            str+=s[i];
            if(dp[ind][i]){
                path.push_back(str);
                solve(i+1,s,path,ans,dp);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isP(s,i,j)){
                    dp[i][j]=1;
                }
            }
        }
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,path,ans,dp);
        return ans;
    }
};