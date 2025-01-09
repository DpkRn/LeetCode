class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(auto it:words){
            string str=it;
            // bool flag=true;
            int i;
            for( i=0;i<pref.size()&&str.size();i++){

               if(pref[i]!=str[i]){
                    // flag=false;
                    break;
               }
            }
            if(i==pref.size()) cnt++;
        }
        return cnt;
    }
};