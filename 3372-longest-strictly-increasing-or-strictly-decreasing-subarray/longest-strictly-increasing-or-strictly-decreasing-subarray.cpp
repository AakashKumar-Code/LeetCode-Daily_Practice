class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        int inc=0, dec=0;

        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                if(inc==0) inc=1;
                inc++;
                dec=0;
            }else if(nums[i]<nums[i-1]){
                if(dec==0) dec=1;
                inc=0;
                dec++;
            }else{
                inc=0;
                dec=0;
            }
            maxi=max(maxi, max(inc, dec));
        }

        return maxi;
    }
};