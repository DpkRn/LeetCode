class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            vector<int> hash(26,0);
            for(auto it:strs[i]) hash[it-97]++;
            string sorted="";
            for(int j=0;j<26;j++){
                sorted+=to_string(hash[j]);
                sorted+='#';
            } 
            mp[sorted].push_back(strs[i]);
        }
        // for(auto str:mp){
        //     cout<<str.first<<" "<<endl;
        // }
        vector<vector<string>> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};