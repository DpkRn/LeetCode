class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int x, int y) {

        vector<vector<int>> sol;
        int n = 0;
        int step = 1;
        while (n < R * C) {

            for (int i = 0; i < step; ++i) {
                if (x >= 0 and x < R and y >= 0 and y < C)
                    sol.push_back(vector<int>{x, y}), n++;
                y++;
            }
            for (int i = 0; i < step; ++i) {
                if (x >= 0 and x < R and y >= 0 and y < C)
                    sol.push_back(vector<int>{x, y}), n++;
                x++;
            }
            step++;
            for (int i = 0; i < step; ++i) {
                if (x >= 0 and x < R and y >= 0 and y < C)
                    sol.push_back(vector<int>{x, y}), n++;
                y--;
            }
            for (int i = 0; i < step; ++i) {
                if (x >= 0 and x < R and y >= 0 and y < C)
                    sol.push_back(vector<int>{x, y}), n++;
                x--;
            }
            step++;
        }

        return sol;
    }
};