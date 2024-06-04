class Solution {
public:
    int longestPalindrome(string s) {
       
        vector<int> hash(65,0);
        for(auto c: s) hash[c-65]++;
       
        int c=0;
        int isOdd=0;
        for(int i=0;i<65;i++){
            if(hash[i]%2==0) c+=hash[i];
            if(hash[i]%2==1){
                c+=hash[i]-1;
                isOdd=true;
            }
        }
        return isOdd==1?c+1:c;
    }
};