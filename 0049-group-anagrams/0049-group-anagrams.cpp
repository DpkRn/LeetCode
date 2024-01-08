class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<bool> mp(n,true);
        vector<string> sorted=strs;
        for(int i=0;i<n;i++){
            sort(sorted[i].begin(),sorted[i].end());
        }
        vector<vector<string>> ans;
       for(int i=0;i<n;i++){
           if(mp[i]==true){
               string temp=strs[i];
               sort(temp.begin(),temp.end());
               vector<string> v;
               for(int j=0;j<n;j++){
                   if(mp[j]==false) continue;
                    string at=sorted[j];
                   
                   if(temp==at){
                       v.push_back(strs[j]);
                       mp[j]=false;
                   }
               }
               ans.push_back(v);
               }
           
       }
        return ans;
    }
};