class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> idx;
        
        for(auto ch:arr) {
            if(idx[ch]==0) idx[ch]=1;
            else idx[ch]=2;
        }
        for(auto ch:arr){
            if(idx[ch]==1)
            k--;
            if(k==0) return ch;
        }
        return "";

    }
};