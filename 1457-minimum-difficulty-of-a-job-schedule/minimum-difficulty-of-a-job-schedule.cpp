class Solution {
public:

    int n;

    int solve(int ind, int d, vector<int>&arr, vector<vector<int>>&dp){
        if(d==0){
            if(ind>=n) return 0;
            else return 1e9;
        }
        if(dp[ind][d]!=-1) return dp[ind][d];

        int mini=1e9;
        int maxiJ=0;
        int total=0;
        for(int i=ind; i<=(n-d); i++){
            maxiJ=max(maxiJ, arr[i]);
            total=maxiJ+solve(i+1, d-1, arr, dp);
            mini=min(mini, total);
        }
        return dp[ind][d]=mini;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>>dp(n+1, vector<int>(d+1, -1));
        return solve(0, d, jobDifficulty, dp);        
    }
};