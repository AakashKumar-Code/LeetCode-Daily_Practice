class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        long long pro=1;
        int i=0, j=0;
        int cnt=0;
        if(k<=1) return 0;

        for(; j<n; j++){
            pro*=nums[j];
            for(; i<n && pro>=k; i++){
                pro/=nums[i];
            }
            cnt+=(j-i+1);
        }

        return cnt;
    }
};