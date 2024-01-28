class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int j=0; j<n; j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int ldg=1e9, rdg=1e9;
                int up=matrix[i][j]+dp[i-1][j];
                if(j-1>=0) ldg=matrix[i][j]+dp[i-1][j-1];
                if(j+1<n) rdg=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min({up, ldg, rdg});
            }
        }
        int mini = *min_element(dp[n - 1].begin(), dp[n - 1].end());
        return mini;
    }
};