class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0,l=0;
        unordered_map<char,int> mp;
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