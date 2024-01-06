class Solution {
public:
    void solve(int ind,string temp,string &digits,vector<string>&ans,map<char,string> mp){
    if(ind>=digits.size()){
        if(temp!="")
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<mp[digits[ind]].size();i++){
        solve(ind+1,temp+mp[digits[ind]][i],digits,ans,mp);
    }
}
    vector<string> letterCombinations(string digits) {
         map<char,string> mp;
   
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
    vector<string> ans;
    solve(0,"",digits,ans,mp);
        return ans;
    }
};