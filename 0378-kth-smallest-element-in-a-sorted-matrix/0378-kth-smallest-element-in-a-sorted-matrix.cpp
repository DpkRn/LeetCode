class Solution {
public://O(n+m)log(k)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        for(int i=0;i<min(n,k);i++){
            pq.push({matrix[i][0],i,0});
        }
        for(int i=1;i<=k-1;i++){
            int r=pq.top()[1];
            int c=pq.top()[2];
            pq.pop();
            if(c+1<n) pq.push({matrix[r][c+1],r,c+1});
        }
        return pq.top()[0];
    }
};


/*
class Solution {
public:
    //Binary Search on answer (nlogn) o(1)
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
*/
/*
class Solution {
public://using max-heap  O(mnlogk) O(k)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n=matrix.size();
        for(auto it:matrix){
            for(auto el:it){
                pq.push(el);
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }
};
*/

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