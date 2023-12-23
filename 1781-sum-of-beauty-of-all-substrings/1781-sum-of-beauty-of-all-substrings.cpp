class Solution {
    int getBeauti(unordered_map<char,int> &mp){
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto x:mp){
            mini=min(mini,x.second);
            maxi=max(maxi,x.second);
        }
        return (maxi-mini);
    }
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                ans+=getBeauti(mp);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
// int res(unordered_map<char,int>&mp){
//     int mf=-1;
//     int lf=INT_MAX;
//     for(auto &it:mp){
//         mf=max(mf,it.second);
//         if(it.second>=1){
//             lf=min(lf,it.second);
//        }
       
//     }
//      return mf-lf;
// }
//     int beautySum(string s) {
//         int ans=0;
//         for(int i=0;i<s.size();i++){
//             unordered_map<char,int>mp;
//             for(int j=i;j<s.size();j++){
//                 mp[s[j]]++;
//                 ans=ans+res(mp);
//             }
//         }
//         return ans;
//     }
// };