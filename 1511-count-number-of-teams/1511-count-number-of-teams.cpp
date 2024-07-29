class Solution {
public:
    int get(auto &rating){
        int n=rating.size();
        int res=0;
        for(int i=0;i<n;i++){
            int smaller=0;int greater=0;
            for(int j=0;j<n;j++){
                if(j<i&&rating[j]<rating[i]){
                    smaller++;
                }
                if(i<j&&rating[j]>rating[i]){
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