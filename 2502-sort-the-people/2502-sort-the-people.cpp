class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> details; vector<string> ans;int n=heights.size();
        for(int i=0;i<n;i++) details.push_back({heights[i],names[i]});
        sort(details.begin(),details.end(),greater<>());
        for(auto it:details) ans.push_back(it.second);
        return ans;
    }
};
/*

 vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=heights.size();
        priority_queue<pair<int,string>> pq;
        for(int i=0;i<n;i++) pq.push({heights[i],names[i]});
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

*/