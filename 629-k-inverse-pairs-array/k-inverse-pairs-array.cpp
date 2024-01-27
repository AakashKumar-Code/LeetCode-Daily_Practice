class Solution {
public:

    int mod=1e9+7;

    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0]=1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                int ans=0;
                for(int inv=0; inv<=min(i-1, j); inv++){
                    ans=(ans+dp[i-1][j-inv])%mod;
                }
                dp[i][j]=ans;
            }
        }
        return dp[n][k];
    }
};