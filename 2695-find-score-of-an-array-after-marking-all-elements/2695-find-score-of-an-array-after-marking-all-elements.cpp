class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<int> ind(n,0),marked(n,0);
        for(int i=0;i<n;i++){
            ind[i]=i;
        }

        sort(begin(ind),end(ind),[&](int &a,int &b){
            return nums[a] == nums[b] ? a < b : nums[a] < nums[b];
        });
        // for(auto it:ind) cout<<it<<" ";

        long long score=0;
        for(auto i:ind){
            if(!marked[i]){
                score+=nums[i];
                marked[i]=1;
                if(i-1>=0) marked[i-1]=1;
                if(i+1<n)  marked[i+1]=1;
            }
        }
        return score;
    }
};