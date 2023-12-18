class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int n=nums.size();
        mp[0]=1;
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
           cnt=cnt+mp[sum-k];
           mp[sum]++;
        }
        return cnt;
    }
};