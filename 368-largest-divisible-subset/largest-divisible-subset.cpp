class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1);
        vector<int>prev(n, -1);
        int maxi=-1e9, max_i=-1;


        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                        if(dp[i]>maxi){
                            maxi=dp[i];
                            max_i=i;
                        }
                    }
                }
            }
        }

        vector<int>ans;
        while(max_i!=-1){
            ans.push_back(nums[max_i]);
            max_i=prev[max_i];
        }
        reverse(ans.begin(), ans.end());
        if(ans.size()==0) return {nums[0]};
        return ans;
    }
};