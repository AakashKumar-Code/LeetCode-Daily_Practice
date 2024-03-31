class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();

        int minI=-1;
        int maxI=-1;
        int err=-1;

        long long ans=0;

        for(int i=0; i<n; i++){

            if(nums[i]<minK || nums[i]>maxK){
                err=i;
            }

            if(nums[i]==minK) minI=i;

            if(nums[i]==maxK) maxI=i;

            int smaller=min(minI, maxI);

            long long temp=smaller-err;

            ans+=temp<=0?0:temp;

        }

        return ans;
    }
};