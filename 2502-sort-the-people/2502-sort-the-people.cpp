class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n=heights.size();
    vector<int> sorted(n);
    vector<string> ans(n);
    for(int i=0;i<n;i++) sorted[i]=i;
    sort(sorted.begin(),sorted.end(),[&](int a,int b){
        return heights[a]>heights[b];
    });

    for(int i=0;i<n;i++){
        ans[i]=names[sorted[i]];
    }
    return ans;
}
};
/*

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
*/