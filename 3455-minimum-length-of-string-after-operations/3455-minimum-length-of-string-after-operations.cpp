class Solution {
public:
    int minimumLength(string s) {
       vector<int> arr(26,0);
       int n=s.size();
       for(int i=0;i<n;i++){
        arr[s[i]-'a']++;
        if(arr[s[i]-'a']>2) arr[s[i]-'a']-=2;
       } 
       int sum=0;
       for(int i=0;i<26;i++) sum+=arr[i];
       return sum;
    }
};