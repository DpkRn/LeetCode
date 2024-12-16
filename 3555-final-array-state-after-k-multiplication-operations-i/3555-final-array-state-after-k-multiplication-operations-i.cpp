#define P pair<int,int>
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<P,vector<P>,greater<P>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++) pq.push({nums[i],i});
        while(k--){
            int idx=pq.top().second;
            pq.pop();
            nums[idx]*=multiplier;
            pq.push({nums[idx],idx});
        }
        return nums;
    }
};