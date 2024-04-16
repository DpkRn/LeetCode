class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(auto i:num){
            while(!ans.empty()&&ans.back()>i&&k) {            
                ans.pop_back(); 
                k--;
            }
            if(!ans.empty()||i!='0')
            ans.push_back(i);
        }      
        while(!ans.empty()&&k--){
            ans.pop_back();
        }
        return ans.empty()?"0":ans;
    }
};