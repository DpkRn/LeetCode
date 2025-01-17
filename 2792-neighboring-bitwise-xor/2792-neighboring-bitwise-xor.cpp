class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int x=0;
        for(int i=0;i<n;i++){
            x^=derived[i];
        }
        if(x==0) return true;
        return false;
    }
};