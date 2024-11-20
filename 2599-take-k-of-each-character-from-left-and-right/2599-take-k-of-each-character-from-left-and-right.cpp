class Solution {
public:
   
    int takeCharacters(string s, int k) {
        vector<int> freq(3,0);
        int n=s.size();
        for(auto it:s) freq[it-'a']++;
        if(freq[0]<k||freq[1]<k||freq[2]<k) return -1;
        int canRemove=0;
        int i=0;
        for(int j=0;j<n;j++){
            freq[s[j]-'a']--;
            while(i<n&&(freq[0]<k||freq[1]<k||freq[2]<k)){
                freq[s[i]-'a']++;
                i++;
            }
            canRemove=max(canRemove,j-i+1);
          
        }
        return n-canRemove;

    }
};