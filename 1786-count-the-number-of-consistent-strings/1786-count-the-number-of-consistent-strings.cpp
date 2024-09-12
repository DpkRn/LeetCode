class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,bool> mp;
        for(auto ch:allowed) mp[ch]=true;
        int cnt=0;
        for(auto word:words){
            int flag=true;
            for(int i=0;i<word.size();i++){
                if(mp[word[i]]==false) flag=false;
            }
            cnt+=(flag==true);
        }
        return cnt;
    }
};