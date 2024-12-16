class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        long long cnt=0;
        int l=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(abs(mp.rbegin()->first-mp.begin()->first)>2){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            cnt+=(i-l+1);
        }
        return cnt;

    }
};