class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0,l=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            //expand till we get repeating
            if(mp[s[i]]==0){
                mp[s[i]]++;
            }else{
                //shrink till we get removed repeating character
                while(mp[s[i]]>0){
                   mp[s[l]]--; 
                    l++;
                }
                //before moving next increase the count of current char
                mp[s[i]]++;
            }
            maxi=max(maxi,i-l+1);            
        }
        return maxi;
    }
};