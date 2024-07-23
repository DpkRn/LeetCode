class Solution {
public:
 
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n=nums.size();
        for(auto it:nums) freq[it]++;
        sort(begin(nums),end(nums),[&](int a, int b){
            return freq[a]==freq[b]?a>b:freq[a]<freq[b];
        });
        return nums;
    }

};