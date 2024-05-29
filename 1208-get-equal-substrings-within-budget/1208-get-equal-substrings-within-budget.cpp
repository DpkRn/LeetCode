class Solution {
public:
   
    int equalSubstring(string s, string t, int maxCost) {
        int l=0,r=0;
        int n=s.size();
        int m=0;
        int maxi=0;
        for(r=0;r<n;r++){
            m=m+(abs(s[r]-t[r]));
//             if(m<=maxCost){
               
//             }else{
                while(m>maxCost){
                    m=m-abs(s[l]-t[l]);
                    l++;
                }
            //}
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};