class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
        if(str1.size()>str2.size()) return false;
        int n=str1.size();
        string fromLeft=str2.substr(0,n);
        string fromRight=str2.substr(str2.size()-n,n);
        if(str1==fromLeft&&str1==fromRight) return true; return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0,n=words.size();
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j])) cnt++;
            }
        }
        return cnt;
    }
};