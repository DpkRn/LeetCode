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
/*
//for two gap
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                bool lleft=(i>1?flowerbed[i-2]==0:true);
                bool left=(i>0?flowerbed[i-1]==0:true);
                bool right=(i<flowerbed.size()-1?flowerbed[i+1]==0:true);
                bool rright=(i<flowerbed.size()-2)?flowerbed[i+2]==0:true;
                 
                if(left&&right&&lleft&&rright){
                    flowerbed[i]=1;
                    cnt++;
                    
                }
            }
        }
        for(auto it:flowerbed) cout<<it<<" ";
        // cout<<cnt<<endl;
        return cnt>=n;
    }
};
*/