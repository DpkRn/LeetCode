class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='o'||ch=='i'||ch=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            int s=words[i].size()-1;
            if(isVowel(words[i][0])&&isVowel(words[i][s])){
                pre[i+1]=pre[i]+1;

            }else{
                pre[i+1]=pre[i];
            }
        }
        for(auto it:pre) cout<<it<<" ";

        vector<int> ans;
        for(auto it:queries){
            int l=it[0]; int r=it[1];
            int no=pre[r+1]-pre[l];
            ans.push_back(no);
        }
        return ans;
    }
};