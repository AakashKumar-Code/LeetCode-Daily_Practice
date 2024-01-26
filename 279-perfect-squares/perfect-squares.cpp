class Solution {
public:

    int solve(int i, int len, int n, vector<int>&temp, vector<vector<int>>&dp){
        if(n==0) return 0;
        if(i>=len) return 1e9;
        if(dp[i][n]!=-1) return dp[i][n];

        int take=1e9;
        if(n>=temp[i]){
            take=1+solve(0, len, n-temp[i], temp, dp);
        }
        int ntake=solve(i+1, len, n, temp, dp);
        return dp[i][n]=min(take, ntake);
    }

    int numSquares(int n) {
        vector<int>temp;
        for(int i=1; i*i<=n; i++){
            temp.push_back(i*i);
        }
        int sz=temp.size();
        vector<vector<int>>dp(sz+1, vector<int>(n+1, -1));
        return solve(0, sz, n, temp, dp);
    }
};