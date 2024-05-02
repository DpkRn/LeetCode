class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi=-1;
        for(auto it:nums){
            if(it<0){
                 for(auto op:nums){
                    if(op>0&&abs(it)==op){
                        maxi=max(op,maxi);
                    }
                 }
            }
           
        }
        
        return maxi;
    }
};