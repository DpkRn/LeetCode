class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    unordered_map<int,int> mp;
    int i=0;
    for(auto it:heights) mp[it]=i++;
    sort(begin(heights),end(heights),greater<int>());
    vector<string> ans;
    for(auto it:heights) ans.push_back(names[mp[it]]);
    return ans;
}
};