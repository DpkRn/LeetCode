class Solution {
public:
    int minLength(string s) {
        string ans="";
        for(auto c:s){
            if(ans.empty()){
                ans.push_back(c);
            }else if(c=='B'&&ans.back()=='A'){
                    ans.pop_back();
                }
            else if(c=='D'&&ans.back()=='C'){
                   ans.pop_back();
                }else{
                    ans.push_back(c);
                }
        }
        return ans.size();
    }
};