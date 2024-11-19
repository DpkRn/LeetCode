class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int k) {
        int cnt=0,n=f.size();
        for(int i=0;i<n;i++){
           if(f[i]==0){
             bool left=(i==0)||f[i-1]==0;
            bool right=(i==n-1)||f[i+1]==0;
            if(left&&right){
                cnt++;
                f[i]=1;  
            }
           }
          
        }
        return cnt>=k;
    }
};