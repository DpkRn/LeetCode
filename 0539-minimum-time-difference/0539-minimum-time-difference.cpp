class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> nums;
        for(auto it:timePoints){
            int x=stoi(it.substr(0,2))*60+stoi(it.substr(3));
            nums.push_back(x);
        }
        sort(nums.begin(),nums.end());
        int mini=1e9;
        int n=nums.size();
        for(int i=1;i<n;i++){
            mini=min({mini,nums[i]-nums[i-1],1440-nums[i]+nums[0]});
        }
        return mini;
    }
};