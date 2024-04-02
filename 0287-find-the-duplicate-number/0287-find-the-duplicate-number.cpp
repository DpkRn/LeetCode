class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> cnt;
        for(auto it:nums){
            cnt[it]++;
            if(cnt[it]==2) return it;
        }
        return -1;
    }
};