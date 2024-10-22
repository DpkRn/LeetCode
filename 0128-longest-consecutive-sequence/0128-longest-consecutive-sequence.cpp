class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it:nums) st.insert(it);
        int maxi=0;
        for(auto &it:nums){
            if(!st.contains(it-1)){
                int currCnt=0;
                int currNo=it;
                while(st.contains(currNo)){
                    currCnt++; currNo++;
                    maxi=max(maxi,currCnt);
                }
            }
        }
        return maxi;
    }
};