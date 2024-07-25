
class NumArray {
public:
    vector<int> t;
    vector<int> nums;
    int n;
    NumArray(vector<int>& nums) {
         n=nums.size();
        t.resize(4*n);
        this->nums=nums;
        buildTree(0,0,n-1);
    }
    void buildTree(int v,int lt,int rt){
        if(lt==rt){
            t[v]=nums[lt];
            return;
        }
        int mid=(lt+rt)>>1;
        buildTree(2*v+1,lt,mid);
        buildTree(2*v+2,mid+1,rt);
        t[v]=t[2*v+1]+t[2*v+2];
    }
    
    void update(int index, int val) {
        update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sumRange(0,0,n-1,left,right);
    }
    void update(int v,int lt,int rt,int idx,int val){
        if(lt==idx&&rt==idx){
            t[v]=val;
           // nums[idx]=val;
            return ;
        }
        int mid=(lt+rt)>>1;
        if(idx<=mid) update(2*v+1,lt,mid,idx,val);
        else
        update(2*v+2,mid+1,rt,idx,val);
        t[v]=t[2*v+1]+t[2*v+2];
    }
    int sumRange(int v,int lt,int rt,int left,int right){
        if(rt<left||right<lt) return 0;
        if(left<=lt&&rt<=right) return t[v];
        int mid=(lt+rt)>>1;
        int leftSum=sumRange(2*v+1,lt,mid,left,right);
        int rightSum=sumRange(2*v+2,mid+1,rt,left,right);
        return leftSum+rightSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */