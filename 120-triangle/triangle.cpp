class Solution {
public:

    int solve(int i, int j, int &n, vector<vector<int>>&arr, vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int d=arr[i][j]+solve(i+1, j, n, arr, dp);
        int dr=arr[i][j]+solve(i+1, j+1, n, arr, dp);
        return dp[i][j]=min(d, dr);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(0, 0, n, triangle, dp);
    }
};