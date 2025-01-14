class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=max(A.size(),B.size());
        vector<int> ans;
       for(int k=0;k<n;k++){
         int cnt=0;
         for(int i=0;i<=min(k,(int)A.size()-1);i++){
            for(int j=0;j<=min(k,(int)B.size()-1);j++){
                if(A[i]==B[j]){
                    cnt++;
                }
            }
        }
        ans.push_back(cnt);
       }
        return ans;
    }
};