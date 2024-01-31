class Solution {
public:
    bool isValid(string str){
        string temp=""; 
        int n=str.size();
        for(int i=0;i<n;i++){
            if(str[i]=='(')
                temp.push_back('(');
            else {
                if(temp.empty()) return false;
                temp.pop_back();
            }
        }
        if(temp.size()==0) return true;
        else return false;
    }
    void f(int n,string &path,auto &ans){
        if(n==0){
            if(isValid(path)) ans.push_back(path);
            return ;
        }
        path.push_back(')');
        f(n-1,path,ans);
        path.pop_back();
        path.push_back('(');
        f(n-1,path,ans);
        path.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        f(2*n,path,ans);
        return ans;
    }
};