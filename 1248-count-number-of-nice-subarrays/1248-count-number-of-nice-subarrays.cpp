class Solution {
public:
    //to get strictely equal to we will find first <=k and after that we will substact <=k-1
    int get(auto &nums,int k){
        int n=nums.size();
        int l=0,cnt=0,odd=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1) odd++;
            while(odd>k){
                if(nums[l]%2==1) odd--;l++;
            }
            if(odd<=k) cnt+=(i-l+1);
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return get(nums,k)-get(nums,k-1);
        
    }
};