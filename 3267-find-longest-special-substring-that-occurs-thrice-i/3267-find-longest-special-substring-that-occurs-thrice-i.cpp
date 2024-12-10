class Solution {
public:
    vector<int> LPS(string pat) {
        int n = pat.size();
        int l = 0, i = 1;
        vector<int> lps(n, 0);
        while (i < n) {
            if (pat[i] == pat[l]) {
                l++;
                lps[i] = l;
                i++;
            } else {
                if (l != 0) {
                    l = lps[l - 1];
                    continue;
                }
                i++;
            }
        }
        return lps;
    }

    int getmatch(string str, string pat) {
        int n = str.size();
        int t = pat.size();
        vector<int> lps = LPS(pat);
        int i = 0, l = 0;
        int cnt = 0;
        while (i < n) {
            if (str[i] == pat[l]) {
                i++;
                l++;
            } else {
                if (l != 0) {
                    l = lps[l - 1];
                    continue;
                }
                i++;
            }
            if (l == t) {
                cnt++;
                l = lps[l - 1];
            }
        }
        

            return cnt;
        }

        int maximumLength(string s) {
           int n=s.size();
           int ans=-1;
           for(int i=0;i<n;i++){
            string temp="";
                for(int j=i;j<n;j++){
                    temp+=s[i];
                    int cnt=getmatch(s,temp);
                    if(cnt>=3){
                        ans=max(ans,(int)temp.size());
                    }
                }
           }
           return ans;
        }
    };