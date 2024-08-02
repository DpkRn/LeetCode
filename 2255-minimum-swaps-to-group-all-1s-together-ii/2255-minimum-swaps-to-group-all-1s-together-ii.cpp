class Solution {
public:
    int minSwaps(vector<int>& nums) {
       int n=nums.size(),ans=1e9;
        int total=0; int zeroCnt=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
            zeroCnt+=(1-nums[i]);
        }
        int cnt=0;
        for(int i=0;i<total;i++){
            cnt+=(1-nums[i]);
        }
        ans=min(ans,cnt);
        int l=0; int r=total; 
        while(r<n+total&&l<n){
            r=r%n; 
            cnt+=(1-nums[r]);
            r++;
            cnt-=(1-nums[l]);
            l++;
            ans=min(ans,cnt);
        }
        return ans;
        
    }
};