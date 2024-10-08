class Solution {
public:
      int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> mp;
        mp[0]=1;
        int psum = 0, res = 0;
        for (int i : A) {
            psum += i;
            res += mp[psum - S];
            mp[psum]++;
           
        }
        return res;
    }
};