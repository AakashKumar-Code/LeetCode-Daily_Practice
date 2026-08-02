class Solution {
public:

    int solve(int i, int j, vector<int>&piles, vector<vector<int>>&dp){
        if(i==j) return piles[i];
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int take_i=piles[i]+min(solve(i+2, j, piles, dp), solve(i+1, j-1, piles, dp));
        int take_j=piles[j]+min(solve(i+1, j-1, piles, dp), solve(i, j-2, piles, dp));

        return dp[i][j]=max(take_i, take_j);
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int alice=solve(0, n-1, piles, dp); 
        int sum=0;
        for(int i=0; i<n; i++) sum+=piles[i];
        return 2*alice>sum;       
    }
};