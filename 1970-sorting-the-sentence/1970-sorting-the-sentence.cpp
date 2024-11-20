class Solution {
public:
    string sortSentence(string s) {
        int n=s.size();
        vector<string> strs;
        string str="";
        for(int i=0;i<n;i++){
            
            if(s[i]==' '){
                strs.push_back(str);
                str="";
            }else{
                str.push_back(s[i]);
            }
        }
        strs.push_back(str);


        sort(strs.begin(),strs.end(),[](string a,string b){
            return a[a.size()-1]<b[b.size()-1];
        });
        string ans="";
        for(auto it:strs){
            ans+=it; ans.pop_back(); 
            ans+=" ";
        }
        ans.pop_back();
        return ans;
       

    }
};