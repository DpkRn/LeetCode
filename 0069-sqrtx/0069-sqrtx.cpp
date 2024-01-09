class Solution {
public:
    int mySqrt(int x) {
        int l=0;int h=x;
        while(l<=h){
            int mid=h-(h-l)/2;
            if(1ll*mid*mid<=x){
                l=mid+1;
            }else
                h=mid-1;
        }
        return h;
        
    }
};