class Solution {
public:
    int n;
    int dp[2501][2501]; // Update size to avoid out-of-bounds access

    int solve(int i, int prev, vector<int>& nums) {
        if (i == n) return 0;
        if (prev != -1 && dp[i][prev] != -1) return dp[i][prev];

        int ntake = solve(i + 1, prev, nums);

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums);
        }

        if (prev != -1) dp[i][prev] = max(take, ntake);
        return max(take, ntake);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, nums);
    }
};
