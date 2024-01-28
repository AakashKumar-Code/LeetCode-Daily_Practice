class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int maxi=-1e9;
            int maxSum=-1e9;
            int len=0;
            for(int p=i; p<min(k+i, n); p++){
                maxi=max(maxi, arr[p]);
                len++;
                int ops=maxi*len+dp[p+1];
                maxSum=max(maxSum, ops);
            }
            dp[i]=maxSum;
        }
        return dp[0];
    }
};