class Solution {
public:
    bool isValid(string s) {
        string str="";
        int n=s.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            if(s[i]==')'||s[i]=='}'||s[i]==']'){ 
                    if(str.empty()==true) return false;
                    if(s[i]==')'&&str.back()!='(')
                    return false;
                    if(s[i]=='}'&&str.back()!='{')
                    return false;             
                    if(s[i]==']'&&str.back()!='[')
                    return false;
                    str.pop_back();
            }else str.push_back(s[i]);
                  cout<<str<<" ";  
        }
       
        if(str=="")
        return true;
        else return false;
       
    }
};