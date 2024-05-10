class Solution {
public:
    int getSmallerThanM(auto &mat,int m){
        int n=mat.size();
        int cnt=0;
        for(auto it:mat){
            cnt+=upper_bound(it.begin(),it.end(),m)-it.begin();
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        
        int l=mat[0][0]; int h=mat[n-1][n-1];
         int ans=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            int cnt=getSmallerThanM(mat,m);
            if(cnt>=k){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    //O(mnlog mn) O(mn)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ans;
        for(auto it:matrix){
           ans.insert(ans.end(),it.begin(),it.end());
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};
*/