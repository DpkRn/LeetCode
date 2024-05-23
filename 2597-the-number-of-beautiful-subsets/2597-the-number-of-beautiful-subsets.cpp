class Solution {
public:
    int solve(int i,vector<int> &nums,int k,int hash[]){
        if(i>=nums.size()) return 1;
        int left=0;
        if(nums[i]-k<0||hash[nums[i]-k]==0){
            hash[nums[i]]++;
            left=solve(i+1,nums,k,hash);
            hash[nums[i]]--;
        }
        int right=solve(i+1,nums,k,hash);
        return left+right;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int hash[10001];
        sort(nums.begin(),nums.end());
        memset(hash,0,sizeof(hash));
        return solve(0,nums,k,hash)-1;
        
    }
};