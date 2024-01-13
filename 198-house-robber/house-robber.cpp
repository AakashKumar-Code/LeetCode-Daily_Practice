class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int prev2=nums[0];
        int prev=max(nums[1], nums[0]);
        int cur;
        for(int i=2; i<n; i++){
            if(i-2<n) cur=max(prev, nums[i]+prev2);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};