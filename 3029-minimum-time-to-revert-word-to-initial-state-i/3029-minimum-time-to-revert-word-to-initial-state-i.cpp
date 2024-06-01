class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        int i=0;
        int ans=0;
        while(i<n){
            i=i+k;
            ans++;
            int l=0;
            int j;
            for( j=i;j<n;j++){
                if(word[l]!=word[j]) break;
                l++;
            }
            if(j==n) return ans;
        }
        return ans;
    }
};