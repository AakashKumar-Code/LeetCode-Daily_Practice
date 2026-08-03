class Solution {
public:

    int solve(int i, int n, vector<int>&arr, vector<int>&dp){

        if(i>=n) return 0;

        if(dp[i]!=INT_MIN) return dp[i];

        int one=-1e9, two=-1e9, three=-1e9;

        one=arr[i]-solve(i+1, n, arr, dp);

        if(i+1<n) two=arr[i]+arr[i+1]-solve(i+2, n, arr, dp);

        if(i+2<n) three=arr[i]+arr[i+1]+arr[i+2]-solve(i+3, n, arr, dp);

        return dp[i]=max(three, max(one, two));        
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n, INT_MIN);

        int alice=solve(0, n, stoneValue, dp);
        if(alice>0) return "Alice";
        else if(alice==0) return "Tie";
        else return "Bob";

    }
};