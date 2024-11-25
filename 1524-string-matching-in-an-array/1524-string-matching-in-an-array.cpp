class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
       // vector<string> ans;
        unordered_set<string> st;
        int n=words.size();
        for(int i=0;i<n;i++){
            string text=words[i];
            for(int j=0;j<words.size();j++){
                if(i==j) continue;
                string pat=words[j];
                for(int k=0;k<text.size();k++){
                    int l;
                    for( l=0;l<pat.size();l++){
                        if(text[k+l]!=pat[l]){
                            break;
                        }
                    }
                    if(l==pat.size()){
                        st.insert(pat);
                        break;
                    }
                }
            }



        }
        vector<string> ans(st.begin(),st.end());
        return ans;
    }
};