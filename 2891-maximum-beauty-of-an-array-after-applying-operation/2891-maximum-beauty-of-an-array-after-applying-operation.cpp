class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>> deq;
        vector<pair<int,int>> intervals;
        for(auto it:nums){
            intervals.push_back({it-k,it+k});
        }
        sort(begin(intervals),end(intervals));

        int ans=0;
        for(auto interval:intervals){
            while(!deq.empty()&&deq.front().second<interval.first){
                deq.pop_front();
            }
            deq.push_back({interval});
            ans=max(ans,(int)deq.size());
        }
        return ans;
    }
};