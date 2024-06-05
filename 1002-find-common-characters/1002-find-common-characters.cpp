class Solution {
public:
    vector<int> get(int i,vector<int> hash,vector<string>& words){
        if(i>=words.size()) return hash;
        vector<int> curr(26,0);
        for(int j=0;j<words[i].size();j++){
            curr[words[i][j]-97]++;
        }
        for(int i=0;i<26;i++){
            hash[i]=min(hash[i],curr[i]);
        }
        return get(i+1,hash,words);
    }
    vector<string> commonChars(vector<string>& words) {
        vector<int> hash(26,0);
        for(auto i=0;i<words[0].size();i++){
            hash[words[0][i]-97]++;
        }
        hash=get(0,hash,words);
        vector<string> ans;
        for(int i=0;i<26;i++){
            char c=i+97;
            string s=""; s.push_back(c);
            for(int j=0;j<hash[i];j++){

                ans.push_back(s);
            }
        }
        return ans;
    }
};