class Solution {
public:
    int get(vector<int>& nums, int k){
        if(k<0) return 0; 
        int n=nums.size();
        int l=0;
        int oddcnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1) oddcnt++;
            while(oddcnt>k){
                if(nums[l]%2==1) oddcnt--;
                l++;
            }
            if(oddcnt<=k) ans+=(i-l+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return get(nums,k)-get(nums,k-1);
    }
};