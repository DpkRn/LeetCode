class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        
        if (k > 0) {
            // Sum the next k elements
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= k; j++) {
                    ans[i] += code[(i + j) % n];
                }
            }
        } else if (k < 0) {
            // Sum the previous |k| elements
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= -k; j++) {
                    ans[i] += code[(n + i - j) % n];
                }
            }
        }
        
        // If k == 0, the ans array remains all zeros.
        return ans;
    }
};
