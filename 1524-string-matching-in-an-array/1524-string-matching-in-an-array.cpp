class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
       vector<string> ans;
        int n=words.size();

        sort(words.begin(),words.end(),[&](string &a,string &b){
            return a.size()<b.size();
        });

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[j].find(words[i])!=-1){
                    ans.push_back(words[i]); break;
                }
            }
        }
        return ans;
    }
};