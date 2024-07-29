class Solution {
public:
    int numTeams(vector<int>& rating) {
       int n=rating.size();
      int res=0;
        for(int i=0;i<n;i++){
            int less[2]={}; int greater[2]={};
            for(int j=0;j<n;j++){
                if(rating[j]<rating[i]){
                    less[j<i]++;
                }
                if(rating[j]>rating[i]){
                    greater[j<i]++;
                }
            }
            res+=less[0]*greater[1]+less[1]*greater[0];
        }
        return res;
    }
};