class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr = 1;
        for (int i = 0; i < n; ++i) {
            res.push_back(curr);
            if (curr * 10 <= n) curr *= 10;
            else {
                while (curr % 10 == 9 || curr >= n) curr /= 10;
                curr += 1;
            }
        }
        return res;
    }
};