class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int temp=-1;
        int cnt=1;
         int sum=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) cnt++;
            else{
                if(temp!=-1){
                   sum+=min(temp,cnt);
                }
                temp=cnt;
                cnt=1;
            }
        }
        if(temp!=-1) sum+=min(temp,cnt);
        return sum;
    }
};