class Solution {
public:
    int findCenter(vector<vector<int>>& edge) {
        return edge[0][1]==edge[1][0]||edge[0][1]==edge[1][1]?edge[0][1]:edge[0][0];
    }
};