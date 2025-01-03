class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();    
       long long sum=0;
       for(auto it:nums) sum+=it;
        long long curr=0;
        int cnt=0;
        for(int i=0;i<n-1;i++){ 
            curr+=nums[i]*1ll;
            cnt+=(curr>=(sum-curr));
        }
        return cnt;
    }
};