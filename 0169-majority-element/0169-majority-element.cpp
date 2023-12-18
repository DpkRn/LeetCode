class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int lead=-1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0)
            lead=nums[i];
            if(lead==nums[i])
            cnt++;
            else cnt--;
        }

        return lead;
    }
};