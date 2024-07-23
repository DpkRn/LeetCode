class Solution {
public:
 static bool com(pair<int,int> a,pair<int,int> b){
    if(a.second!=b.second)
    return a.second<b.second;
    else return a.first>b.first;   
}
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(auto it:nums) mp[it]++;
        vector<pair<int,int>> vec;
        for(auto it:mp){
            for(int i=0;i<it.second;i++)
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),com);
        vector<int> ans;
        for(auto it:vec) ans.push_back(it.first);
        return ans;
    }

};