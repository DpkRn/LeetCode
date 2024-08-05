class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> freq;
        unordered_map<string,int> idx;

        int i=0;
        for(auto ch:arr) 
        {
            freq[ch]++;
            if(idx.find(ch)==idx.end()){
                idx[ch]=i++;
            }
        }
        sort(arr.begin(),arr.end(),[&](string a,string b){
            if(freq[a]!=freq[b])
            return freq[a]<freq[b];
            else return idx[a]<idx[b];
        });
        for(auto it:arr) cout<<it<<" ";
        return freq[arr[k-1]]!=1?"":arr[k-1];

    }
};