class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        vector<long long>pre(n, 0);
        for(int i=0; i<n; i++){
            sum+=nums[i];
            pre[i]=sum;
        }
        long long maxi=LLONG_MIN;
        unordered_map<int, vector<int>>mp1;
        
        for(int i=0; i<n; i++){
            if(mp1.find(nums[i]-k)!=mp1.end()){
                for(auto &it:mp1[nums[i]-k]){
                    maxi=max(maxi, pre[i]-pre[it]+nums[it]);
                }                
            }
            if(mp1.find(nums[i]+k)!=mp1.end()){
                for(auto &it:mp1[nums[i]+k]){
                    maxi=max(maxi, pre[i]-pre[it]+nums[it]);
                }
            }
            mp1[nums[i]].push_back(i);
        }
        return maxi==LLONG_MIN?0:maxi;
    }
};