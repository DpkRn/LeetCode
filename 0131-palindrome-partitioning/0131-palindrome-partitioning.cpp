class Solution {
public:
    bool isP(string str,int l,int r){
        if(l>=r) return true;
        if(str[l]!=str[r])
            return false;
        return isP(str,l+1,r-1);
    }
    void solve(int ind,string s,vector<string> &path,vector<vector<string>> &ans){
        if(ind>=s.size()){
            ans.push_back(path);
            return;
        }
    
        for(int i=ind;i<s.size();i++){
            if(isP(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,path,ans);
        return ans;
    }
};