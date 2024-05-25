class Solution {
public:
    vector<string> ans;
     unordered_map<string,int> mp;
    void dfs(int i,string &s,string path){
        if(i>=s.size()){
            ans.push_back(path);
            return;
        }
        string str="";
        for(int j=i;j<s.size();j++){
            str+=s[j];
            if(mp[str]>0){
                path+=path.size()==0?"":" ";
                path+=str;
                dfs(j+1,s,path);
               // cout<<path<<endl;
                int l=path.size()-1;
                while(path.size()>0 and path[l]!=' '){
                    path.pop_back();
                    l--;
                }
                if(path.size()>0) path.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       
        for(auto it:wordDict){
            mp[it]++;
        }
        string path="";
        dfs(0,s,path);
        return ans;
        
    }
};