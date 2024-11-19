class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        long long ans=0;
        long long sum=0;
        unordered_map<int,int> cnt;
      for(int i=0;i<n;i++){
        sum+=nums[i];
        while(cnt[nums[i]]>0||i-l+1>k){
            cnt[nums[l]]--;
            sum-=nums[l];
            l++;
        }
        cnt[nums[i]]++;
        if(i-l+1==k){
            ans=max(ans,sum);
        }
      }
        return ans;
        
    }
};