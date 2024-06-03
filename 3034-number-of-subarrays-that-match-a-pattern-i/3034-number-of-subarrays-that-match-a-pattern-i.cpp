class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size();
        int m=pattern.size();
        int cnt=0;
        for(int i=0;i<n-m;i++){
            bool flag=true;
            for(int k=0;k<m;k++){
                if(pattern[k]==1&&nums[i + k + 1] <= nums[i + k]){
                    flag=false; break;
                }else if(pattern[k]==0&&nums[i + k + 1] != nums[i + k]){
                    flag=false; break;
                }else if(pattern[k]==-1&&nums[i + k + 1] >= nums[i + k]){
                    flag=false; break;
                }
            }
            if(flag==true) cnt++;
        }
        return cnt;
    }
};