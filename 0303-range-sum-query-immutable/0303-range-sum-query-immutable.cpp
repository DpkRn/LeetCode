class NumArray {
public:
    vector<int> prefixSum;

    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefixSum.resize(n);
        for(int i=0;i<n;i++){
            prefixSum[i]=i!=0?prefixSum[i-1]+nums[i]:nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return left!=0?prefixSum[right]-prefixSum[left-1]:prefixSum[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */