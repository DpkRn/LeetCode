class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, maxi = 1;
        int m = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < m)
                cnt = 0;
            else if (nums[i] == m)
                cnt++;
            else {
                cnt = 1;
                maxi = 1;
            }

            m = max(m, nums[i]);
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};