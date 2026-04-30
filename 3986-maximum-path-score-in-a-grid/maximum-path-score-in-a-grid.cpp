class Solution {
public:

    int n, m;
    int solve(int i, int j, int cost, int k, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){

        if(i>=n || j>=m) return -1e9;
        int newCost=cost+(grid[i][j]>0?1:0);
        if(newCost>k) return -1e9;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j][newCost]!=-1) return dp[i][j][newCost];
        int rgt=solve(i, j+1, newCost, k, grid, dp);
        int dwn=solve(i+1, j, newCost, k, grid, dp);
        if(rgt==-1e9 && dwn==-1e9) return dp[i][j][newCost]=-1e9;
        return dp[i][j][newCost]=max(rgt, dwn)+grid[i][j];
    }


    int maxPathScore(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));

        int ans=solve(0, 0, 0, k, grid, dp);
        return ans==-1e9?-1:ans;
        
    }
};