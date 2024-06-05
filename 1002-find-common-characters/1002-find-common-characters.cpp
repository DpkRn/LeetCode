class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> hash(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                hash[i][words[i][j]-97]++;
            }
        }
        
        vector<string> ans;
        string str="";
        for(int j=0;j<26;j++){
            int mini=1e9;
            for(int i=0;i<n;i++){
               mini=min(mini,hash[i][j]);
            }
            char c=j+97;
            for(int k=0;k<mini;k++){
                str+=c;
            }
        }
        cout<<str;
        for(int i=0;i<str.size();i++){
            string s="";
            s.push_back(str[i]);
            ans.push_back(s);
        }
        return ans;
    }
};