class Solution {
public:
    int getLessThanK(auto &nums,int k){
        if(k<0) return 0;
        int cnt=0;
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            while(nums[i]-nums[j]>k) j++;
            cnt+=(i-j);
        }
        return cnt;
    }
    int countKDifference(vector<int>& nums, int k) { 
        sort(nums.begin(),nums.end());
        return getLessThanK(nums,k)-getLessThanK(nums,k-1);    
    }
};