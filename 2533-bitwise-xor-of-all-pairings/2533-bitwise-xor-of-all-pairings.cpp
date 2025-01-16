class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int ans1=0;
        int ans2=0;
        int ans=0;
        for(auto it:nums1) ans1^=it;
        for(auto it:nums2) ans2^=it;
        if(n1%2==1&&n2%2==1 ){
            return ans1^ans2;
        }else if(n1%2==1){
           
           return ans2;

        }else if(n2%2==1){
            return ans1;
        }else
        return ans;

    }
};