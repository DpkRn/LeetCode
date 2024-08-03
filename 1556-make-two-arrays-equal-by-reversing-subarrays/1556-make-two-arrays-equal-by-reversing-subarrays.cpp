class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp1,mp2;
        int n=arr.size();
        for(auto i=0;i<n;i++){
            mp1[arr[i]]++; mp2[target[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp2[arr[i]]!=mp1[arr[i]]) return 0;
        }
    return true;
    }
};