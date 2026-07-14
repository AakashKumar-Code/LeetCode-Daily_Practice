class Solution {
public:

    int mod=1e9+7;

    int gcd(int a, int b){
        if((a%b)==0){
            return b;
        }else return gcd(b, a%b);
    }

    int solve(int i, int first, int second, int n, vector<int>&nums, vector<vector<vector<int>>>&dp){
        if(i==n){
            if(first!=0 && first==second){
                return 1;
            }
            return 0;
        }

        if(dp[i][first][second]!=-1) return dp[i][first][second];

        int skip=(solve(i+1, first, second, n, nums, dp))%mod;
        int take1=(solve(i+1, gcd(first, nums[i]), second, n, nums, dp))%mod;
        int take2=(solve(i+1, first, gcd(second, nums[i]), n, nums, dp))%mod;

        int ans=(skip+take1)%mod;
        ans=(ans+take2)%mod;

        return dp[i][first][second]=ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();

        int maxi=-1e9;
        for(int i=0; i<n; i++) maxi=max(maxi, nums[i]);

        vector<vector<vector<int>>>dp(n, vector<vector<int>>(maxi+1, vector<int>(maxi+1, -1)));

        return solve(0, 0, 0, n, nums, dp);
        
    }
};