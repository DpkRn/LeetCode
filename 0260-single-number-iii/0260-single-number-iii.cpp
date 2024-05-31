class Solution {
public:
    #define ll long long
    vector<int> singleNumber(vector<int>& nums) {
         int a=0; int b=0;
        int n=nums.size();
        ll xorr=0;
        for(int i=0;i<n;i++){
           xorr^=nums[i];
        }
        ll mask=(xorr&(xorr-1))^xorr;
        for(int i=0;i<n;i++){
            if(mask&nums[i]){
                a^=nums[i];
            }else{
                b^=nums[i];
            }
        }
        return {a,b};
    }
};