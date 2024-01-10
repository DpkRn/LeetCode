class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string str;
        ss>>str;
        return str.size();
    }
};