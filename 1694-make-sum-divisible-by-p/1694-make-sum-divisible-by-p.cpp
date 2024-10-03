class Solution {
public:
    long long minSubarray(vector<int>& nums, int p) {
        int n=nums.size(),s=0;
        long long sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%p==0) return 0; 
        long long k=sum%p;
        long long ans=1e9;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(long long i=0;i<n;i++){
            s=(s+nums[i]%p)%p;
            int x=(s-k+p)%p;
            if(mp.find(x)!=mp.end()){
                ans=min(ans,i-mp[x]);
            }
            mp[s]=i;
        }
        return ans==n?-1:ans;
    }
};