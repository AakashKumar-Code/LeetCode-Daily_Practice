class Solution {
public:

    int n;
    int sW;
    int dp[1002][1002];
    int solve(int i, vector<vector<int>>&books, int remW, int maxH){
        if(i>=n){
            return maxH;
        }
        if(dp[i][remW]!=-1) return dp[i][remW];
        int keep=1e9, skip=1e9;
        if(books[i][0]<=remW){
            keep=solve(i+1, books, remW-books[i][0], max(maxH, books[i][1]));
        }
        skip=maxH+solve(i+1, books, sW-books[i][0], books[i][1]);
        return dp[i][remW]=min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n=books.size();
        sW=shelfWidth;
        memset(dp, -1, sizeof(dp));
        return solve(0, books, shelfWidth, 0);
    }
};