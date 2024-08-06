class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int> freq(26,0);
        for(auto ch : word){
            freq[ch-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
       
        int result=0;
        int cnt=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) return result;
            result+=(freq[i]*(i/8+1));
        }
        return result;
    }
};