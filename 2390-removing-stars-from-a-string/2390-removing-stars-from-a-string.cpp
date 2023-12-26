class Solution {
public:
    string removeStars(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*')
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
       return ans;
        
    }
};