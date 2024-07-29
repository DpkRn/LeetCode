class Solution {
public:
    int get(auto &rating){
        int n=rating.size();
        int res=0;
        for(int i=0;i<n;i++){
            int smaller=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]){
                    smaller++;
                }
            }
            int greater=0;
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i]){
                    greater++;
                }
            }
            res+=(smaller*greater);
        }
        return res;
    }
    int numTeams(vector<int>& rating) {
       int n=rating.size();
       int ans=get(rating);
       reverse(rating.begin(),rating.end());
       ans+=get(rating);
       return ans;
    }
};