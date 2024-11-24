class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                bool left=i>0?flowerbed[i-1]==0:true;
                bool right=(i<flowerbed.size()-1)?flowerbed[i+1]==0:true;
                if(left&&right){
                    flowerbed[i]=1;
                    cnt++;
                }
            }
        }
        return cnt>=n;
    }
};