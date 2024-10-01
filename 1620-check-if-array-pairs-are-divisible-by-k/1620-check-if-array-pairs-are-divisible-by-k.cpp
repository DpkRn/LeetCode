class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto &it:arr){
            int x=it%k;
            it=x>=0?x:x+k;
             if(mp[(k-it)%k]>0) mp[(k-it)%k]--;
            else
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second>0) return false;
        }
        return true;
    }
};