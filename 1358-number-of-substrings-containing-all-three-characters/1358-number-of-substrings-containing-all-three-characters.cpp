class Solution {
public:
    //count substring ending at particular character by checking minimum window or lastSeen among three
    int numberOfSubstrings(string s) {
        int n=s.size();
        int cnt=0,r=0,hash[3]={-1,-1,-1};
      while(r<n){
           hash[s[r]-'a']=r;
           if(hash[0]!=-1&&hash[1]!=-1&&hash[2]!=-1){
               int mini=min({hash[0],hash[1],hash[2]});
               cnt+=mini+1;
           }
          r++;
       }
        return cnt;
    }
};
/*
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
             int hash[3]={0};
            for(int j=i;j<n;j++){
                hash[s[j]-'a']=1;
                if(hash[0]+hash[1]+hash[2]==3){
                    cnt+=n-j;
                    break;   
                }
            }
        }
        return cnt;
    }
};
*/