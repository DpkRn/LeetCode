class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0,n=s.size();
        unordered_map<char,int> mp;
        int l=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]]>1){
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};