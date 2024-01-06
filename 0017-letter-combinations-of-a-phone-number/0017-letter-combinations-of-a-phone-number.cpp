class Solution {
public:
    void solve(int ind,string temp,string &digits,vector<string>&ans,vector<string> &mp){
    if(ind>=digits.size()){
        if(temp!="")
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<mp[digits[ind]-'0'].size();i++){
        solve(ind+1,temp+mp[digits[ind]-'0'][i],digits,ans,mp);
    }
}
    vector<string> letterCombinations(string digits) {
    vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    solve(0,"",digits,ans,mp);
        return ans;
    }
};