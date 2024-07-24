class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int> order;
        for(auto it:nums){
            int temp=it;
            string numstr=to_string(temp);
            int mapped=0;
            for(char ch:numstr){
                int digit=ch-'0';
                mapped=mapped*10+mapping[digit];
            }
            order[it]=mapped;
           
        }
         sort(begin(nums),end(nums),[&](int a,int b){
                return order[a]<order[b];
            });
        return nums;
    }
};