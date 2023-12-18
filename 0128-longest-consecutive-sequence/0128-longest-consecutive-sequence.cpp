class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int cnt=1,maxv=1;
        
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]-1)
                cnt++;
                else if(nums[i-1]==nums[i])
                     continue;
                     else
                     cnt=1;
            
            maxv=max(cnt,maxv);
        }
        return maxv;
    }
};