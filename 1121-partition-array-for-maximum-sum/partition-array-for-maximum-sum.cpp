class Solution {
public:

    int solve(int i, int n, int &k, vector<int>&arr, vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=-1e9;
        int maxSum=-1e9;
        int len=0;
        for(int p=i; p<min(k+i, n); p++){
            maxi=max(maxi, arr[p]);
            len++;
            int ops=maxi*len+solve(p+1, n, k, arr, dp);
            maxSum=max(maxSum, ops);
        }
        return dp[i]=maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1, -1);
        return solve(0, n, k, arr, dp);
    }
};