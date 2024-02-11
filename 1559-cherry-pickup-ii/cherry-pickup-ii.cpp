class Solution {
public:

    int n, m;

    int solve(int row, int col1, int col2, vector<vector<int>>& arr, 
    vector<vector<vector<int>>>&dp){
        if(row>=n) return 0;
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];

        int cherry=arr[row][col1];
        if(col1!=col2) cherry+=arr[row][col2];

        int maxi=0;
        for(int dc1=-1; dc1<=1; dc1++){
            for(int dc2=-1; dc2<=1; dc2++){
                int ncol1=col1+dc1;
                int ncol2=col2+dc2;
                
                if(ncol1>=0 && ncol1<m && ncol2>=0 && ncol2<m){
                    maxi=max(maxi, solve(row+1, ncol1, ncol2, arr, dp));
                }
            }
        }
        return dp[row][col1][col2]=maxi+cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m-1, grid, dp);
    }
};