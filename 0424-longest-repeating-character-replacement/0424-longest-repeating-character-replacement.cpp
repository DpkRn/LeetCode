class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        if(n==0) return 0;
        unordered_map<char,int> mp;
        int l=0,maxCount=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            maxCount=max(maxCount,mp[s[i]]);
            if(((i-l+1)-maxCount)>k){
                mp[s[l++]]--;
            }
        }
        return n-l;
    }
};