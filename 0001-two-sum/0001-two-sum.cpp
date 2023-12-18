class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int req=target-nums[i];
            if(mp.find(req)!=mp.end())
            return {mp[req],i};
            mp[nums[i]]=i;
        }
        return {-1};
    }
};