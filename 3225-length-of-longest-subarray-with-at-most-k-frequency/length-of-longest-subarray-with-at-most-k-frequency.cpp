class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0, j=0;
        unordered_map<int, int>mpp;
        int maxi=0;
        for(; j<n; j++){
            mpp[nums[j]]++;

            for(; i<n && mpp[nums[j]]>k; i++){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
            }

            maxi=max(maxi, j-i+1);
        }
        return maxi;
    }
};