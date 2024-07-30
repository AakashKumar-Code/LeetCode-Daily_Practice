class NumArray {
public:

    vector<int>segTree;

    void bT(int i, int l, int r, vector<int>&nums){
        if(l==r){
            segTree[i]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        bT(2*i+1, l, mid, nums);
        bT(2*i+2, mid+1, r, nums);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }

    int getSum(int i, int l, int r, int s, int e){
        if(l>e || r<s) return 0;
        if(l>=s && r<=e) return segTree[i];
        int mid=l+(r-l)/2;
        return getSum(2*i+1, l, mid, s, e)+getSum(2*i+2, mid+1, r, s, e);
    }

    void updateR(int i, int l, int r, int ind, int val){
        if(l==r){
            segTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(ind<=mid){
            updateR(2*i+1, l, mid, ind, val);
        }else{
            updateR(2*i+2, mid+1, r, ind, val);
        }
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }

    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        segTree=vector<int>(4*n, 0);
        bT(0, 0, n-1, nums);        
    }
    
    void update(int index, int val) {
        updateR(0, 0, n-1, index, val);
        
    }
    
    int sumRange(int left, int right) {
        return getSum(0, 0, n-1, left, right);                
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */