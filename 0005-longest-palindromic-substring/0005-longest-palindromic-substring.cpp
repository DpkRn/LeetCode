class Solution {
    string getLen(string s,int left,int right){
        int n=s.size();
        while(left>=0&&right<n&&s[left]==s[right]){
            left--;right++;
        }
        return s.substr(left+1,right-left-1);
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        string ans="";
        for(int i=0;i<n-1;i++){
           string lenOdd=getLen(s,i,i);
           string lenEven=getLen(s,i,i+1);
           string maxi=lenOdd.size()>lenEven.size()?lenOdd:lenEven;
           if(maxi.size()>ans.size())
           ans=maxi;
           
        }
        return ans;
    }
};