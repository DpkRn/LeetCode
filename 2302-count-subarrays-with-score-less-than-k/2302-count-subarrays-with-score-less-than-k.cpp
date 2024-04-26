class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
     int n=nums.size();
     long long cnt=0,l=0,r=0;
     long long s=0;
        while(r<n){
            s+=nums[r];
            while((r-l+1)*s>=k){
                s-=nums[l];
                l++;
            }
            if((r-l+1)*s<k)
                cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
};