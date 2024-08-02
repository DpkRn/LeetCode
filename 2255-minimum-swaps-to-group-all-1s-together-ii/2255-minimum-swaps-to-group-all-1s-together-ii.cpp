class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int l=0,n=nums.size(),ans=1e9;
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        
        vector<int> ps(n+1,0);
        for(int i=0;i<n;i++){
            ps[i+1]=ps[i]+1-nums[i];
        }
        for(auto it:ps) cout<<it<<" ";
        for(int i=0;i<n;i++){
            int l=i; int r=(i+total)%n;
            if(l<=r) ans=min(ans,(ps[r]-ps[l]));
            else
            ans=min(ans,ps[n]-ps[l]+ps[r]);
        }

        return ans;
        
    }
};