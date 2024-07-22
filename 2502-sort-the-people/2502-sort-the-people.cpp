//using priority Queue 
class Solution {
public:
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
};