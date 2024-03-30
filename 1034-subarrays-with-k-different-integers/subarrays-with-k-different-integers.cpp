class Solution {
public:

    int solve(vector<int>&nums, int k){
        unordered_map<int, int>mpp;

        int n=nums.size();

        int i=0, j=0;
        int cnt=0;

        for(; j<n; j++){
            mpp[nums[j]]++;

            for(; i<n && mpp.size()>k; i++){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);

            }
            if(mpp.size()<=k) cnt+=(j-i+1);
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return solve(nums, k)-solve(nums, k-1);
        
        
    }
};