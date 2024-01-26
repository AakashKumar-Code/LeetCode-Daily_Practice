class Solution {
public:
    const int mod = 1e9 + 7;
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));

        for (int move = 1; move <= maxMove; move++) {
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    for (int i = 0; i < 4; i++) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            dp[move][r][c] = (dp[move][r][c] + 1) % mod;
                        } else {
                            dp[move][r][c] = (dp[move][r][c] + dp[move - 1][nr][nc]) % mod;
                        }
                    }
                }
            }
        }

        return dp[maxMove][startRow][startColumn];
    }
};
