class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>mpp;
        int n=nums.size();
        mpp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(mpp.find(sum-goal)!=mpp.end()){
                ans+=mpp[sum-goal];
            }
            mpp[sum]++;
        }
        return ans;
    }
};