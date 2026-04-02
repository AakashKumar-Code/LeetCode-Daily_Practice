class Solution {
public:
    int n, m;
    int solve(int r, int c, int p, vector<vector<int>>&coins, 
    vector<vector<vector<int>>>&dp){
        if(r==n-1 && c==m-1){
            if(coins[n-1][m-1]<0 && p>0) return 0;
            else return coins[n-1][m-1];
        }
        if(r>=n || c>=m) return -1e9;
        if(dp[r][c][p]!=-1e9) return dp[r][c][p];
        int right=0, down=0;
        if(coins[r][c]<0 && p>0){
            right=max(coins[r][c]+solve(r, c+1, p, coins, dp), 
            solve(r, c+1, p-1, coins, dp));
            down=max(coins[r][c]+solve(r+1, c, p, coins, dp), 
            solve(r+1, c, p-1, coins, dp));
        }else{
            right=coins[r][c]+solve(r, c+1, p, coins, dp);
            down=coins[r][c]+solve(r+1, c, p, coins, dp);
        }
        return dp[r][c][p]=max(right, down);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));
        return solve(0, 0, 2, coins, dp);        
    }
};