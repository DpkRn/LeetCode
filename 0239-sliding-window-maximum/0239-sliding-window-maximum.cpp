class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        int i=0;
        deque<int> dq;
        for(i=0;i<n;i++){
            if(!dq.empty()&&i-dq.front()>=k) dq.pop_front();
            while(!dq.empty()&&nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);       
        }
        return ans;

    }
};