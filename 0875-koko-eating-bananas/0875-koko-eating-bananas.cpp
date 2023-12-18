class Solution {
public:
    int isValid(vector<int>& piles,int mid,int h){
        long long totalHours=0;
        for(int i=0;i<piles.size();i++){
            totalHours+=ceil((double)piles[i]/mid);
            if(totalHours>h) return totalHours;
        }   
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1; int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            long long mid=(low+high)>>1;
            long long val=isValid(piles,mid,h);
            if(val<=h) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};