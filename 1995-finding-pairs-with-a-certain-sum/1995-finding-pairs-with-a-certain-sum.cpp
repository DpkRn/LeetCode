class FindSumPairs {
    vector<int> nums1,nums2;
    unordered_map<int,int> cnt;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(auto it:nums2){
            cnt[it]++;
        }
    }
    
    void add(int index, int val) {
        int temp=nums2[index];
        nums2[index]+=val;
        cnt[temp]--;
        cnt[nums2[index]]+=1;
    }
    
    int count(int tot) {
        int c=0;
        for(auto it:nums1){
            c+=cnt[tot-it];
        }

        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */