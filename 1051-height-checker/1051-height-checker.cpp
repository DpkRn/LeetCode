class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> org=heights;
        int cnt=0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<org.size();i++){
            if(org[i]!=heights[i]) cnt++;
        }
        return cnt;
    }
};