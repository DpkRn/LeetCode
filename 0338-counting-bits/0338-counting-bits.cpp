class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        //every n bits are extension of n-1 bits 
        // if suppose n-1 bit no is 101 lets suppose n=4 so to make n-1 bit to n bit either 0 or 1 will be added
        // and it will depend on odd or even no so first we will change ith to -1 bits by shifting right and then 
        // add 1 if it is odd or add 0 if it is even
        for(int i=1;i<=n;i++){
            ans[i]=ans[i>>1]+i%2;
        }
        return ans;
    }
};