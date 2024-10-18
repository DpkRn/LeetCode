class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0; int n=nums.size(); if(n==1) return true;
        for(int i=1;i<n;i++){
            cnt+=nums[i-1]>nums[i];
        }
        cnt+=nums[0]<nums[n-1];
        return cnt<=1;
    }
};