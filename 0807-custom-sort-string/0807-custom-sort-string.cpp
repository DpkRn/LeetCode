class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> ind;
        int i=0;
        for(char ch:order) ind[ch]=i++;
        sort(s.begin(),s.end(),[&](char a,char b){
            return ind[a]<ind[b]; 
            
        });
        return s;
    }
};