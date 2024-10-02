class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> arr1=arr;
        int n=arr.size();
        if(n==0) return {};
        sort(arr1.begin(),arr1.end());
        
        mp[arr1[0]]=1;
        for(int i=1;i<n;i++){
            if(mp.find(arr1[i])==mp.end()){
                mp[arr1[i]]=mp[arr1[i-1]]+1;
            }else{
                mp[arr1[i]]=mp[arr1[i-1]];
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};