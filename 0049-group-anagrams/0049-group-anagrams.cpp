class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        //sort(strs.begin(),strs.end());
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            vector<string> v=it.second;
            vector<string> temp;
            for(auto str:v) temp.push_back(str);
            ans.push_back(temp);
        }
        return ans;
    }
};