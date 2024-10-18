class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(),cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt=0;;
            cnt+=nums[i];
            ans=max(ans,cnt);
        }
        return ans;
    }
};