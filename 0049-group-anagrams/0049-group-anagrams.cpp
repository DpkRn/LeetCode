class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> mp;
        for(auto i:strs){
            string word=i;
            sort(word.begin(),word.end());
            mp[word].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto temp:mp)
            ans.push_back(temp.second);
        return ans;
        
    }
};