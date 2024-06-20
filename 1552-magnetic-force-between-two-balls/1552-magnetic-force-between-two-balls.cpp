class Solution {
public:
    int get(int mid,vector<int>& position,int m){
       int cnt=1;
        int prevInd=0;
       for(int i=1;i<position.size();i++){
            if(position[i]-position[prevInd]>=mid){
                cnt++; prevInd=i;
            }
       }
       return cnt>=m;
        
    }
    int maxDistance(vector<int>& position, int m) {
        int low=1;
        int high=*max_element(position.begin(),position.end());
        sort(position.begin(),position.end());
       
        int ans=-1;
        while(low<=high){
            int mid=high-(high-low)/2;
            
            if(get(mid,position,m)){
                ans=mid; low=mid+1;
            }else high=mid-1;
        }
        return ans;
    }
};