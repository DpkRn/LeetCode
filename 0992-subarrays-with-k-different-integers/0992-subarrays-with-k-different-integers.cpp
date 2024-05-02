class Solution {
public:
    int uptoK(auto &nums,int k){
         int n=nums.size();
        int hash[n+1];
        memset(hash,0,sizeof(hash));
        int ans=0,cnt=0,l=0;
        if(k<0) return 0;
        for(int i=0;i<n;i++){
            
            hash[nums[i]]++;
            if(hash[nums[i]]==1) cnt++;
            
            while(cnt>k){
                hash[nums[l]]--;
                if(hash[nums[l]]==0) cnt--;
                l++;
            }
            if(cnt<=k){
                ans+=(i-l+1);
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return uptoK(nums,k)-uptoK(nums,k-1);
    }
};