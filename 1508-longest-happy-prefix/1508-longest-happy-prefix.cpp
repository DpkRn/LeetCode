class Solution {
public:
    
    string longestPrefix(string s) {
        vector<int> pi(s.length() + 1, 0);
        pi[0] = -1;
        int k = -1;
              
        for (int i = 1; i <= s.length(); i++) {
            while(k >= 0 && s[k] != s[i - 1]) k = pi[k];
            pi[i] = ++k;
        }
        
        return s.substr(0, pi[s.length()]);
    }
};