class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        vector<int>tmp(n);
        for(int i=0; i<n; i++){
            tmp[(i+k)%n]=nums[i];
        }        
        nums=tmp;
        return;        
    }
};