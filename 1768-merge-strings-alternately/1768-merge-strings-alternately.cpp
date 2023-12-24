
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       int l1=word1.size(),l2=word2.size();
        int i=0;
        string str="";
        while(i<l1||i<l2){
            if(i<l1)
                str=str+word1[i];
            if(i<l2)
                str=str+word2[i];
            
            i++;
        }
        return str;
    }
};

/*
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str="";
        int n1=word1.size();
        int n2=word2.size();
        int l=0;
        int r=0;
        while(l<n1&&r<n2){
            str+=word1[l++];
            str+=word2[r++];
        }
        while(l<n1) str+=word1[l++];
        while(r<n2) str+=word2[r++];
        
        return str;
    }
};

*/