class Solution {
public:
//solve this equation  sum + m * (n - 1) = x * n   and   x = minNum + m where m=required moves ,x=element after m moves, minNum=minimum no. and sum=total sum
    int minMoves(vector<int>& nums) {
       int n=nums.size();
       int mini=1e9+1,sum=0;
       for(auto &it:nums){
        mini=min(mini,it); sum+=it;
       }
       return sum-mini*n;
    }
};