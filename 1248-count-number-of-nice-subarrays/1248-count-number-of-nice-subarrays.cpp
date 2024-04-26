class Solution {
public:
    //to get strictely equal to we will find first <=k and after that we will substact <=k-1
    int get(auto &nums,int k){
        int n=nums.size();
        int l=0,r=0,cnt=0,odd=0;
        while(r<n){
            if(nums[r]&1!=0) odd++;
            while(odd>k){
                if(nums[l]&1!=0) odd--; l++;
            }
            if(odd<=k){
                cnt+=(r-l+1);
            }
            r++;           
        }
         return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return get(nums,k)-get(nums,k-1);
        
    }
};