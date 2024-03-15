class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        long long preP=1;
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i]=preP;
            preP*=nums[i];
        }
        preP=1;
        for(int i=n-1; i>=0; i--){
            ans[i]*=preP;
            preP*=nums[i];
        }
        return ans;
    }
};